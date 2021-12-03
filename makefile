CC = g++
CFLAGS = -g -Wall

chess: ChessMain.o functions.o ChessBoard.o Piece.o EmptyPiece.o King.o
	$(CC) $(CFLAGS) -o chess ChessMain.o functions.o ChessBoard.o Piece.o EmptyPiece.o King.o

functions.o: functions.cpp
	$(CC) $(CFLAGS) -c functions.cpp

ChessMain.o: ChessMain.cpp 
	$(CC) $(CFLAGS) -c ChessMain.cpp

ChessBoard.o: ChessBoard.cpp 
	$(CC) $(CFLAGS) -c ChessBoard.cpp

Piece.o: Classes/Piece.cpp
	$(CC) $(CFLAGS) -c Classes/Piece.cpp

EmptyPiece.o: Classes/EmptyPiece.cpp
	$(CC) $(CFLAGS) -c Classes/EmptyPiece.cpp

King.o: Classes/King.cpp
	$(CC) $(CFLAGS) -c Classes/King.cpp

test: testmain.cpp
	$(CC) $(CFLAGS) -o test testmain.cpp

clean:
	-rm *.o