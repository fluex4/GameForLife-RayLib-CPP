#pragma once
#include "grid.hpp"

class Simulation{
    public:
        Simulation(int width,int height,int cellSize)
        :grid(width,height,cellSize),temp(width,height,cellSize),run(false){};
        void Draw();
        void SetCellValue(int row,int column,int value);
        int countLiveNeighbours(int row,int column);
        void Update();
        bool IsRunning(){return run;};
        void Start(){run=true;};
        void Stop(){run=false;}; 
        int GetCellValue(int row,int column){return grid.GetValue(row,column);}
        void FillRandom(){grid.fillRandom();};
        void Clear(){grid.clear();};
        void Toggle(int row,int column);
    private:
        Grid grid;
        Grid temp;
        bool run;
};