CC = g++
CFLAGS = -g -Wall

chess: ChessMain.o functions.o ChessBoard.o Piece.o EmptyPiece.o King.o Pawn.o Rook.o Bishop.o Knight.o Queen.o
	$(CC) $(CFLAGS) -o chess ChessMain.o functions.o ChessBoard.o Piece.o EmptyPiece.o King.o Pawn.o Rook.o Bishop.o Knight.o Queen.o

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

Pawn.o: Classes/Pawn.cpp
	$(CC) $(CFLAGS) -c Classes/Pawn.cpp

Rook.o: Classes/Rook.cpp
	$(CC) $(CFLAGS) -c Classes/Rook.cpp

Bishop.o: Classes/Bishop.cpp
	$(CC) $(CFLAGS) -c Classes/Bishop.cpp

Knight.o: Classes/Knight.cpp
	$(CC) $(CFLAGS) -c Classes/Knight.cpp

Queen.o: Classes/Queen.cpp
	$(CC) $(CFLAGS) -c Classes/Queen.cpp

test: testmain.cpp
	$(CC) $(CFLAGS) -o test testmain.cpp

clean:
	-rm *.o