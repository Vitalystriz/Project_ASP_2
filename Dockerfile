# Stage 1: Build
FROM gcc:latest AS builder
RUN apt-get update && apt-get install -y cmake libgtest-dev

WORKDIR /app
COPY . .
RUN mkdir build && cd build && cmake .. && make

# Stage 2: App Run (Main target)
FROM ubuntu:latest AS runtime
WORKDIR /app
COPY --from=builder /app/build/src/RecommendationApp .
COPY --from=builder /app/data ./data

CMD ["./RecommendationApp"]

# Stage 3: Test Run
FROM builder AS test_runner
WORKDIR /app/build
CMD ["./tests/runTests"]