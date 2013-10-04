#pragma once

const int WindowWidth = 640;
const int WindowHeight = 480;

enum GAMESTATE { gMENU, gGAME, gGAMEOVER, gCOMPLETE, gPAUSED };
enum MENUSTATE { mMAIN, mOPTIONS, mTUTORIAL, mCREDITS };

extern GAMESTATE mGameState;
extern MENUSTATE mMenuState;