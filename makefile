CC = g++
CFLAGS = -g -Wall

chess: ChessMain.o ChessBoard.o Piece.o
	$(CC) $(CFLAGS) -o chess ChessMain.o ChessBoard.o Piece.o

ChessMain.o: ChessMain.cpp 
	$(CC) $(CFLAGS) -c ChessMain.cpp

ChessBoard.o: ChessBoard.cpp 
	$(CC) $(CFLAGS) -c ChessBoard.cpp

Piece.o: Piece.cpp 
	$(CC) $(CFLAGS) -c Piece.cpp

test: testmain.cpp
	$(CC) $(CFLAGS) -o test testmain.cpp