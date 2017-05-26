{
//example of writing a tree using a struct 

gROOT->Reset();

//Define the structure to hold the variables for each branch
 
struct Photon{
  float pt; 
  float eta;
  float phi;
};

//Declare instance of photon1 and photon2
Photon photon1;
Photon photon2;
//Events
Int_t Events; 

//create a new ROOT file
TFile *f = new TFile("photontree.root", "RECREATE");
//create a TTree
TTree *tree = new TTree("T", "staff data from ascii file");
//create branches with the information from the associated structure
//if applicable
tree->Branch("Events",&Events,"I");
tree->Branch("photon1", &photon1, "pt/F:eta:phi");
tree->Branch("photon2", &photon2, "pt/F:eta:phi");

//Fill the Tree
gRandom->SetSeed();
const Int_t kUPDATE = 500;

for (Int_t i=0; i<20; i++){
tree->Fill();
}//end of for loop filling trees 


// check what the tree looks like
tree->Print();
f->Close();
f->Write();


}
