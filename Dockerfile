FROM gcc:latest

WORKDIR /app

COPY main.cpp .
COPY radix_sort.cpp .
COPY radix_sort.hpp .
COPY in.txt .

RUN g++ main.cpp radix_sort.cpp -o main

CMD ["./main", "in.txt"]