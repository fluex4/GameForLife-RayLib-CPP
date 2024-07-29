#include "simulation.hpp"
#include<vector>
#include<utility>
void Simulation::Draw()
{
    grid.Draw();
}

void Simulation::SetCellValue(int row,int column,int value){
    grid.SetValue(row,column,value);
}

int Simulation::countLiveNeighbours(int row, int column){
     int liveNeighbors = 0;
    std::vector<std::pair<int, int>> neighborOffsets = 
    {
        {-1, 0}, // Directly above
        {1, 0},  // Directly below
        {0, -1}, // To the left
        {0, 1},  // To the right
        {-1, -1},// Diagonal upper left
        {-1, 1}, // Diagonal upper right
        {1, -1}, // Diagonal lower left
        {1, 1}   // Diagonal lower right
    };

    for(const auto& offset : neighborOffsets)
    {
        int neighborRow = (row + offset.first + grid.GetRows()) % grid.GetRows();
        int neighborColumn = (column + offset.second + grid.GetColumns()) % grid.GetColumns();
        liveNeighbors += grid.GetValue(neighborRow, neighborColumn);
    }
    return liveNeighbors;


    return 0;
}

void Simulation::Update(){
    if(IsRunning()){
        for(int row=0;row<grid.GetRows();row++){
            for(int column=0;column<grid.GetColumns();column++){
                int liveNeighbours = countLiveNeighbours(row,column);
                int cellValue=grid.GetValue(row,column);

                if(cellValue == 1){
                
                    if(liveNeighbours > 3 || liveNeighbours <2){
                        temp.SetValue(row,column,0);
                    }
                    else{
                        temp.SetValue(row,column,1);
                    }
                
                }
                else{
                    if(liveNeighbours==3){
                        temp.SetValue(row,column,1);
                    }
                    else{
                        temp.SetValue(row,column,0);
                    }
                }
            }
        }
        grid=temp;
    }
    
}

void Simulation::Toggle(int row, int column){
    if(!IsRunning()){
        SetCellValue(row,column,!grid.GetValue(row,column));
    }
}
