#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Fisherman {
public:
	Fisherman(string fishermanName, int numFish, string fishType);
	void SetFishermanName(string fishermanName);
	void SetNumFish(int numFish);
	void SetFishType(string fishType);
	string GetName() const;
	int GetNumFish() const;
	string GetFishType() const;
	void PrintFishermanInfo() const;
private:
    string fishermanName;
    int numFish;
    string fishType;
};

Fisherman::Fisherman(string fishermanName, int numFish, string fishType) {
    this->fishermanName = fishermanName;
    this->numFish = numFish;
    this->fishType = fishType;
}

void Fisherman::SetFishermanName(string fishermanName) {
    this->fishermanName = fishermanName;
}
void Fisherman::SetNumFish(int numFish) {
    this->numFish = numFish;
}
void Fisherman::SetFishType(string fishType) {
    this->fishType = fishType;
}
string Fisherman::GetName() const {
    return fishermanName;
}
int Fisherman::GetNumFish() const {
    return numFish;
}
string Fisherman::GetFishType() const {
    return fishType;
}
void Fisherman::PrintFishermanInfo() const {
    cout << fishermanName <<" caught "<< numFish << " pounds of " << fishType << endl;
}

int main(int argc, char *argv[]) {
   
   vector<Fisherman*> fishermanList;
   string fishermanName;
   int numFish;
   string fishType;

    //cout << "argc "<<argc<<" argv[0] "<<argv[0]<<" argv[1]= "<<argv[1]<<endl;
    if(argc != 2) {
        cout << "Usage: "<<argv[0]<<" <filename>"<<endl; //error checking
    } 
    else {
        ifstream fileHandle(argv[1]);
        if(!fileHandle.is_open()) {
            cout << "Could not open file"<<endl; //error checking
        } 
        else {
            while(fileHandle >> fishermanName) {
               if (fishermanName == "Search") {
                  break;
               }
               fileHandle >> numFish >> fishType;
                fishermanList.push_back(new Fisherman(fishermanName, numFish, fishType));    
                //cout << fishermanName << "  " << numFish << "  " << fishType << endl;
             }
             //PART 1 - PRINT ENTIRE LIST
             for (int i = 0; i < fishermanList.size(); ++i) {
                cout << fishermanList.at(i)->GetName() << "\t\t" << fishermanList.at(i)->GetNumFish() << "\t" << fishermanList.at(i)->GetFishType() << endl;
             }
             cout << endl;
             
             //PART 2 PRINT FISHERMAN THAT CAUGHT A CERTAIN FISH
             fileHandle >> fishType;
             int fishermanCaught = 0;
            cout << "Type wanted: " << fishType << endl;
             for (int i = 0; i < fishermanList.size(); ++i) {
                if (fishermanList.at(i)->GetFishType() == fishType) {
                cout << fishermanList.at(i)->GetName() << " caught " << fishermanList.at(i)->GetNumFish() << " pounds of " << 
                  fishermanList.at(i)->GetFishType() << endl;
                  ++fishermanCaught;
                }
             }
             if (fishermanCaught = 0) {
                cout << "No " << fishType << endl;
             }

         }
         for (int i = 0; i < fishermanList.size(); ++i) { //delete allocated memory
            Fisherman* fishermanToDelete = nullptr;
            fishermanToDelete = fishermanList.at(i);
				fishermanList.erase(fishermanList.begin() + i);
				delete fishermanToDelete;
				--i;
         }
    }
}