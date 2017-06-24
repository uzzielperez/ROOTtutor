#include <vector>
#include <iostream>
#include <fstream>

#include "TFile.h"
#include "TTree.h"
#include "TCanvas.h"
#include "TFrame.h"
#include "TH1F.h"
#include "TBenchmark.h"
#include "TRandom.h"
#include "TSystem.h"

using namespace std; 

struct Photon_Info{
    double pt; 
    double eta; 
    double phi;  
};

//Declare instance of Photon1, Photon2, Photon3
Photon_Info photon1_info; 
Photon_Info photon2_info;
Photon_Info photon3_info; 
Photon_Info x; 
Photon_Info y; 

//Events
Int_t Events;

//Create vectors of photons 
vector<Photon_Info> triphoton;  
    

void vector_pract(){
    
  //Create a new root file 
    TFile *f = TFile::Open("vectors.root", "RECREATE"); 

   
    //Create a TTree
    TTree *t = new TTree("tvec", "Tree with vectors");
    t->Branch("triphoton", &triphoton);
    t->Branch("Events", &Events, "I");
    t->Branch("photon1_info", &photon1_info, "pt/D:eta:phi");
    t->Branch("photon2_info", &photon2_info, "pt/D:eta:phi");
    t->Branch("photon3_info", &photon3_info, "pt/D:eta:phi");

    //Fill the Tree
    gRandom->SetSeed();
    const Int_t kUPDATE = 500;
  
    for (Int_t i=0; i<50; i++){
    Events = i;
    photon1_info.pt  = gRandom->Gaus(-1,1.5);
    photon1_info.eta = gRandom->Gaus(-0.5,0.5);
    photon1_info.phi = gRandom->Uniform();
    
    photon2_info.pt  = gRandom->Gaus(-1,1.5);
    photon2_info.eta = gRandom->Gaus(-0.5,0.5);
    photon2_info.phi = gRandom->Uniform();
 
    photon3_info.pt  = gRandom->Gaus(-1,1.5);
    photon3_info.eta = gRandom->Gaus(-0.5,0.5);
    photon3_info.phi = gRandom->Uniform();
    
    //Print out photon information
    cout << "Photon1 INFO-> pt: " << photon1_info.pt << "; eta: " << photon1_info.eta << "; phi: " << photon1_info.phi <<endl; 
    cout << "Photon2 INFO-> pt: " << photon2_info.pt << "; eta: " << photon2_info.eta << "; phi: " << photon2_info.phi <<endl; 
    cout << "Photon3 INFO-> pt: " << photon3_info.pt << "; eta: " << photon3_info.eta << "; phi: " << photon3_info.phi <<endl; 
    cout << "----------------------------NEXT EVENT--------------------------------------" <<endl;

    triphoton.push_back(photon1_info); 
    triphoton.push_back(photon2_info); 
    triphoton.push_back(photon3_info); 

    t->Fill();
    }//end of for loop filling trees }

}// end vector_pract()

void print_vector_contents(){

    cout << "Printing out all photon pts stored in triphoton"<< endl; 
for (auto i = triphoton.begin(); i != triphoton.end(); i++)
{
    cout << i->pt<< endl;
 //if ((i%3) ==0) cout << "--------------------NEXT EVENT--------------------" << endl; 
    
}

}//end print_vector_contents 

   bool cmd(const Photon_Info& p1, const Photon_Info& p2)
    {
      return p1.pt < p2.pt; 
    }

void sort_vector_contents(){
   
   sort(triphoton.rbegin(), triphoton.rend(),cmd);
  
}// end sort_vector_contents

  bool ascending(const Photon_Info& p1, const Photon_Info & p2)
{
   return p1.pt > p2.pt; 
}

void sort_ascending_vector_contents(){
  sort(triphoton.rbegin(), triphoton.rend(), ascending);
}

