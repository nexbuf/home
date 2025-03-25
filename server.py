import http.server
import socketserver
import os
import logging

PORT = 8000
UPLOAD_DIR = "uploads"

# Set up logging
logging.basicConfig(level=logging.DEBUG, format="%(asctime)s - %(message)s")
logger = logging.getLogger()

# Create uploads directory
if not os.path.exists(UPLOAD_DIR):
    os.makedirs(UPLOAD_DIR)

class CustomHandler(http.server.SimpleHTTPRequestHandler):
    def do_GET(self):
        self.send_response(200)
        self.send_header("Content-type", "text/html")
        self.end_headers()
        html = """
        <html>
            <body>
                <h1>Upload a File</h1>
                <form method="POST" enctype="multipart/form-data">
                    <input type="file" name="file">
                    <input type="submit" value="Upload">
                </form>
            </body>
        </html>
        """
        self.wfile.write(html.encode())

    def do_POST(self):
        logger.info(f"Received POST from {self.client_address}")
        content_length = int(self.headers["Content-Length"])
        boundary = b"--" + self.headers["Content-Type"].split("=")[1].encode()
        logger.debug(f"Content-Length: {content_length}, Boundary: {boundary}")

        # Read initial lines to find file start
        remaining = content_length
        buffer = b""
        while remaining > 0:
            line = self.rfile.readline()
            remaining -= len(line)
            buffer += line
            if b'filename="' in line:
                try:
                    filename = line.split(b'filename="')[1].split(b'"')[0].decode("utf-8", errors="replace")
                except (IndexError, UnicodeDecodeError) as e:
                    logger.error(f"Error parsing filename: {e}")
                    filename = "unknown_file"
            if line == b"\r\n":  # Empty line marks start of file content
                break

        # Open file and stream content
        filepath = os.path.join(UPLOAD_DIR, filename)
        with open(filepath, "wb") as f:
            # Write any remaining buffer before the file content
            file_start = buffer.rfind(b"\r\n\r\n") + 4
            f.write(buffer[file_start:])

            # Stream the rest, stopping before the final boundary
            while remaining > 0:
                chunk_size = min(8192, remaining)
                chunk = self.rfile.read(chunk_size)
                remaining -= len(chunk)

                # Check for end boundary
                boundary_pos = chunk.find(boundary)
                if boundary_pos != -1:
                    f.write(chunk[:boundary_pos])
                    break
                f.write(chunk)

        logger.info(f"Saved file: {filepath}, Size: {os.path.getsize(filepath)} bytes")
        self.send_response(200)
        self.send_header("Content-type", "text/html")
        self.end_headers()
        self.wfile.write(b"File uploaded successfully!")

# Start the server
with socketserver.TCPServer(("", PORT), CustomHandler) as httpd:
    print(f"Serving at http://your-laptop-ip:{PORT}")
    httpd.serve_forever()