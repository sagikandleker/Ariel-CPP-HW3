#pragma once
#include "Board.h"
#include "Player.h"


class TicTacToe{
	Board gboard;
	Player* w = nullptr;
public:
	TicTacToe(int n):gboard(n){}

	void play(Player& xPlayer ,Player& oPlayer);
	const Player& winner() const
	{
		return *w;
	}
	const Board& board() const
	{
		return gboard;
	}

private:

	bool isWinner(char c)
	{

		if(Col(c)) return true;

		if(Row(c)) return true;

		if(fullDiagonal(c)) return true;

		return false;
	}

	bool fullDiagonal(char c){
		int count=0;
		for(int i=0;i<gboard.size();i++)
		{
			if(c==gboard.mat[i][i].getSymbol())count++;
		}
		if(count == gboard.size()) return true;
		count = 0;

		for(int i=gboard.size()-1;i>=0;i--)
		{
			if(c==gboard.mat[i][i].getSymbol())count++;
		}
		if(count == gboard.size()) return true;
		return false;
	}

	bool Col(char c){

		int count = 0;
		for(int i = 0; i < gboard.size(); i++){
			for(int j = 0; j < gboard.size(); j++){
				if(gboard.mat[i][j].getSymbol() == c) count++;
			}
			if(count == gboard.size()) return true;
			count = 0;
		}
		return false;
	}

	bool Row(char c){
		int count = 0;
		for(int i = 0; i < gboard.size(); i++){
			for(int j = 0; j < gboard.size(); j++){
				if(gboard.mat[j][i].getSymbol() == c) count++;
			}
			if(count == gboard.size()) return true;
			count = 0;
		}
		return false;
	}

	void tryPlay(Player& currentPlayer, Player& otherPlayer)
	{
		BoardIndex cor{0,0};

		try
		{
			Board cBoard = gboard;
			cor = currentPlayer.play(cBoard);
		}
		catch(...)
		{
			w = &otherPlayer;
		}

		if(gboard[cor] == '.')
		{
			gboard[cor] = currentPlayer.getChar();
		}
		else
		{
			w = &otherPlayer;
		}
		if(isWinner(currentPlayer.getChar()))
		{
			w = &currentPlayer;
		}
	}
};