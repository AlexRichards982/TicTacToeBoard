/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} 
		virtual ~TicTacToeBoardTest(){} 
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(TicTacToeBoardTest, smoke_test){
	ASSERT_TRUE(true);
}

TEST(TicTacToeBoardTest, placepiece_X_0_0_t1){
	TicTacToeBoard board;
	Piece output = board.placePiece(0,0);

	ASSERT_EQ(output, X);
}

TEST(TicTacToeBoardTest, placepiece_O_0_0_t2){
	TicTacToeBoard board;
	board.placePiece(1,0);
	Piece output = board.placePiece(0,0);

	ASSERT_EQ(output, O);
}

TEST(TicTacToeBoardTest, placepiece_X_2_2_t1){
	TicTacToeBoard board;
	board.placePiece(2,2);
	Piece output = board.getPiece(2,2);

	ASSERT_EQ(output, X);
}

TEST(TicTacToeBoardTest, placepiece_O_2_2_t2){
	TicTacToeBoard board;
	board.placePiece(1,0);
	Piece output = board.placePiece(2,2);

	ASSERT_EQ(output, O);
}

TEST(TicTacToeBoardTest, placepiece_X_1_2_t3){
	TicTacToeBoard board;
	board.placePiece(2,2);
	board.placePiece(0,0);
	Piece output = board.placePiece(1,2);

	ASSERT_EQ(output, X);
}

TEST(TicTacToeBoardTest, placepiece_O_1_2_t4){
	TicTacToeBoard board;
	board.placePiece(2,2);
	board.placePiece(0,0);
	board.placePiece(1,0);
	Piece output = board.placePiece(1,2);

	ASSERT_EQ(output, O);
}

TEST(TicTacToeBoardTest, placepiece_overwrite_t2){
	TicTacToeBoard board;
	board.placePiece(2,1);
	Piece output = board.placePiece(2,1);

	ASSERT_EQ(output, X);
}

TEST(TicTacToeBoardTest, placepiece_overwrite_t3){
	TicTacToeBoard board;
	board.placePiece(2,1);
	board.placePiece(1,2);
	Piece output = board.placePiece(1,2);

	ASSERT_EQ(output, O);
}

TEST(TicTacToeBoardTest, placepiece_overwrite_t4){
	TicTacToeBoard board;
	board.placePiece(2,2);
	board.placePiece(0,0);
	board.placePiece(1,0);
	Piece output = board.placePiece(1,0);

	ASSERT_EQ(output, X);
}

TEST(TicTacToeBoardTest, placepiece_overwrite_t9){
	TicTacToeBoard board;
	board.placePiece(2,2);
	board.placePiece(0,0);
	board.placePiece(1,0);
	board.placePiece(2,1);
	board.placePiece(0,1);
	board.placePiece(1,1);
	board.placePiece(2,0);
	board.placePiece(0,2);
	board.placePiece(1,2);
	Piece output = board.placePiece(2,1);

	ASSERT_EQ(output, O);
}

TEST(TicTacToeBoardTest, getpiece_oob_row_high){
	TicTacToeBoard board;
	Piece output = board.getPiece(5,2);

	ASSERT_EQ(output, Invalid);
}

TEST(TicTacToeBoardTest, getpiece_oob_column_high){
	TicTacToeBoard board;
	Piece output = board.getPiece(1,10);

	ASSERT_EQ(output, Invalid);
}

TEST(TicTacToeBoardTest, getpiece_oob_row_low){
	TicTacToeBoard board;
	Piece output = board.getPiece(-5,2);

	ASSERT_EQ(output, Invalid);
}

TEST(TicTacToeBoardTest, getpiece_oob_column_low){
	TicTacToeBoard board;
	Piece output = board.getPiece(1,-10);

	ASSERT_EQ(output, Invalid);
}

TEST(TicTacToeBoardTest, getpiece_Blank_t1){
	TicTacToeBoard board;
	board.placePiece(2,0);
	Piece output = board.getPiece(0,0);

	ASSERT_EQ(output, Blank);
}

TEST(TicTacToeBoardTest, getpiece_Blank_t2){
	TicTacToeBoard board;
	board.placePiece(2,1);
	board.placePiece(0,1);
	Piece output = board.getPiece(1,1);

	ASSERT_EQ(output, Blank);
}

TEST(TicTacToeBoardTest, getpiece_Blank_t3){
	TicTacToeBoard board;
	board.placePiece(2,1);
	board.placePiece(2,2);
	board.placePiece(1,1);
	Piece output = board.getPiece(0,0);

	ASSERT_EQ(output, Blank);
}

TEST(TicTacToeBoardTest, getpiece_Blank_t8){
	TicTacToeBoard board;
	board.placePiece(0,0);
	board.placePiece(0,1);
	board.placePiece(0,2);
	board.placePiece(1,0);
	board.placePiece(1,1);
	board.placePiece(1,2);
	board.placePiece(2,0);
	board.placePiece(2,1);
	Piece output = board.getPiece(2,2);

	ASSERT_EQ(output, Blank);
}

TEST(TicTacToeBoardTest, getpiece_X_0_0_t1){
	TicTacToeBoard board;
	board.placePiece(0,0);
	Piece output = board.getPiece(0,0);

	ASSERT_EQ(output, X);
}

TEST(TicTacToeBoardTest, getpiece_O_0_0_t2){
	TicTacToeBoard board;
	board.placePiece(1,0);
	board.placePiece(0,0);
	Piece output = board.getPiece(0,0);

	ASSERT_EQ(output, O);
}

TEST(TicTacToeBoardTest, getpiece_X_2_2_t1){
	TicTacToeBoard board;
	board.placePiece(2,2);
	Piece output = board.getPiece(2,2);

	ASSERT_EQ(output, X);
}

TEST(TicTacToeBoardTest, getpiece_O_2_2_t2){
	TicTacToeBoard board;
	board.placePiece(1,0);
	board.placePiece(2,2);
	Piece output = board.getPiece(2,2);

	ASSERT_EQ(output, O);
}

TEST(TicTacToeBoardTest, getpiece_X_1_2_t3){
	TicTacToeBoard board;
	board.placePiece(2,2);
	board.placePiece(0,0);
	board.placePiece(1,2);
	Piece output = board.getPiece(1,2);

	ASSERT_EQ(output, X);
}

TEST(TicTacToeBoardTest, getpiece_O_1_2_t4){
	TicTacToeBoard board;
	board.placePiece(2,2);
	board.placePiece(0,0);
	board.placePiece(1,0);
	board.placePiece(1,2);
	Piece output = board.getPiece(1,2);

	ASSERT_EQ(output, O);
}

TEST(TicTacToeBoardTest, getpiece_X_1_1_t9){
	TicTacToeBoard board;
	board.placePiece(2,2);
	board.placePiece(0,0);
	board.placePiece(1,0);
	board.placePiece(1,2);
	board.placePiece(2,1);
	board.placePiece(2,0);
	board.placePiece(0,1);
	board.placePiece(0,2);
	board.placePiece(1,1);
	Piece output = board.getPiece(1,1);

	ASSERT_EQ(output, X);
}

TEST(TicTacToeBoardTest, getwinner_unfinished){
	TicTacToeBoard board;
	board.placePiece(2,2);
	board.placePiece(0,0);
	board.placePiece(1,0);
	board.placePiece(1,2);
	Piece output = board.getWinner();

	ASSERT_EQ(output, Invalid);
}

TEST(TicTacToeBoardTest, getwinner_downdiag_X){
	TicTacToeBoard board;
	board.placePiece(2,2);
	board.placePiece(1,0);
	board.placePiece(0,0);
	board.placePiece(1,2);
	board.placePiece(1,1);
	Piece output = board.getWinner();

	ASSERT_EQ(output, X);
}

TEST(TicTacToeBoardTest, getwinner_downdiag_O){
	TicTacToeBoard board;
	board.placePiece(2,1);
	board.placePiece(2,2);
	board.placePiece(1,0);
	board.placePiece(0,0);
	board.placePiece(1,2);
	board.placePiece(1,1);
	Piece output = board.getWinner();

	ASSERT_EQ(output, O);
}

TEST(TicTacToeBoardTest, getwinner_updiag_X){
	TicTacToeBoard board;
	board.placePiece(0,2);
	board.placePiece(1,0);
	board.placePiece(1,1);
	board.placePiece(1,2);
	board.placePiece(2,0);
	Piece output = board.getWinner();

	ASSERT_EQ(output, X);
}

TEST(TicTacToeBoardTest, getwinner_updiag_O){
	TicTacToeBoard board;
	board.placePiece(2,2);
	board.placePiece(0,2);
	board.placePiece(1,0);
	board.placePiece(1,1);
	board.placePiece(1,2);
	board.placePiece(2,0);
	Piece output = board.getWinner();

	ASSERT_EQ(output, O);
}