CC = g++
CFLAGS = -g -Wall

chess: ChessMain.o functions.o ChessBoard.o EmptySquare.o Piece.o Position.o 
	$(CC) $(CFLAGS) -o chess ChessMain.o functions.o ChessBoard.o EmptySquare.o Piece.o Position.o 

functions.o: functions.cpp
	$(CC) $(CFLAGS) -c functions.cpp

ChessMain.o: ChessMain.cpp 
	$(CC) $(CFLAGS) -c ChessMain.cpp

ChessBoard.o: ChessBoard.cpp 
	$(CC) $(CFLAGS) -c ChessBoard.cpp

EmptySquare.o: Classes/EmptySquare.cpp
	$(CC) $(CFLAGS) -c Classes/EmptySquare.cpp

Piece.o: Classes/Piece.cpp 
	$(CC) $(CFLAGS) -c Classes/Piece.cpp 

Position.o: Classes/Position.o
	$(CC) $(CFLAGS) -c Classes/Position.cpp

test: testmain.cpp
	$(CC) $(CFLAGS) -o test testmain.cpp

clean:
	-rm *.o