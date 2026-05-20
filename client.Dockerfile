FROM python:3.11-slim
WORKDIR /app

COPY client.py .

CMD ["python", "client.py", "127.0.0.1", "8080"]

