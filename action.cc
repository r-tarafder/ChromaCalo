/*#include "action.hh"

MyActionInitialization::MyActionInitialization() 
{}

MyActionInitialization::~MyActionInitialization()
{}

void MyActionInitialization::Build() const 
{

    MyPrimaryGenerator *generator = new MyPrimaryGenerator();
     SetUserAction(generator); 

}*/
/*
#include "action.hh"
#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"
#include "EventAction.hh"
#include "SteppingAction.hh"
#include "DetectorConstruction.hh"

using namespace B4;

namespace B4a
{

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

ActionInitialization::ActionInitialization(DetectorConstruction* detConstruction)
 : fDetConstruction(detConstruction)
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void ActionInitialization::BuildForMaster() const
{
  SetUserAction(new RunAction);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void ActionInitialization::Build() const
{
  SetUserAction(new PrimaryGeneratorAction);
  SetUserAction(new RunAction);
  auto eventAction = new EventAction;
  SetUserAction(eventAction);
  SetUserAction(new SteppingAction(fDetConstruction,eventAction));
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

}*/


#include "action.hh"

#include "G4AnalysisManager.hh"
#include "G4Run.hh"
#include "G4RunManager.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"

namespace upo
{

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

RunAction::RunAction()
{
  // set printing event number per each event
  G4RunManager::GetRunManager()->SetPrintProgress(1);

  // Create analysis manager
  // The choice of the output format is done via the specified
  // file extension.
  auto analysisManager = G4AnalysisManager::Instance();

  // Create directories
  //analysisManager->SetHistoDirectoryName("histograms");
  //analysisManager->SetNtupleDirectoryName("ntuple");
  analysisManager->SetVerboseLevel(1);
  analysisManager->SetNtupleMerging(true);
    // Note: merging ntuples is available only with Root output

  // Book histograms, ntuple
  //

  // Creating histograms
  analysisManager->CreateH1("Eshape1" ,"Edep in shape1", 110, 0., 330*MeV);
  analysisManager->CreateH1("Eshape1" ,"Edep in shape1", 110, 0., 330*MeV);
  analysisManager->CreateH1("Eshape1" ,"Edep in shape1", 110, 0., 330*MeV);
  analysisManager->CreateH1("Eshape1" ,"Edep in shape1", 110, 0., 330*MeV);
  analysisManager->CreateH1("Eshape1" ,"Edep in shape1", 110, 0., 330*MeV);
  
  analysisManager->CreateH1("Lshape1" ,"trackL in shape1", 100, 0., 50*cm);
  analysisManager->CreateH1("Lshape1" ,"trackL in shape1", 100, 0., 50*cm);
  analysisManager->CreateH1("Lshape1" ,"trackL in shape1", 100, 0., 50*cm);
  analysisManager->CreateH1("Lshape1" ,"trackL in shape1", 100, 0., 50*cm);
  analysisManager->CreateH1("Lshape1" ,"trackL in shape1", 100, 0., 50*cm);
 
  
  // Creating ntuple
  //
  analysisManager->CreateNtuple("upo", "Edep and TrackL");
  analysisManager->CreateNtupleDColumn("Eshape1");
  analysisManager->CreateNtupleDColumn("Eshape2");
  analysisManager->CreateNtupleDColumn("Eshape3");
  analysisManager->CreateNtupleDColumn("Eshape4");
  analysisManager->CreateNtupleDColumn("Eshape5");
  
  analysisManager->CreateNtupleDColumn("Lshape1");
  analysisManager->CreateNtupleDColumn("Lshape2");
  analysisManager->CreateNtupleDColumn("Lshape3");
  analysisManager->CreateNtupleDColumn("Lshape4");
  analysisManager->CreateNtupleDColumn("Lshape5");
  
  analysisManager->FinishNtuple();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void RunAction::BeginOfRunAction(const G4Run* /*run*/)
{
  //inform the runManager to save random number seed
  //G4RunManager::GetRunManager()->SetRandomNumberStore(true);

  // Get analysis manager
  auto analysisManager = G4AnalysisManager::Instance();

  // Open an output file
  //
  G4String fileName = "upo.root";
  // Other supported output types:
  // G4String fileName = "B4.csv";
  // G4String fileName = "B4.hdf5";
  // G4String fileName = "B4.xml";
  analysisManager->OpenFile(fileName);
  G4cout << "Using " << analysisManager->GetType() << G4endl;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void RunAction::EndOfRunAction(const G4Run* /*run*/)
{
  // print histogram statistics
  //
  auto analysisManager = G4AnalysisManager::Instance();
  if ( analysisManager->GetH1(1) ) {
    G4cout << G4endl << " ----> print histograms statistic ";
    if(isMaster) {
      G4cout << "for the entire run " << G4endl << G4endl;
    }
    else {
      G4cout << "for the local thread " << G4endl << G4endl;
    }

    G4cout << " Eshape1 : mean = "
       << G4BestUnit(analysisManager->GetH1(0)->mean(), "Energy")
       << " rms = "
       << G4BestUnit(analysisManager->GetH1(0)->rms(),  "Energy") << G4endl;
       
       
       
        G4cout << " Eshape2 : mean = "
       << G4BestUnit(analysisManager->GetH1(1)->mean(), "Energy")
       << " rms = "
       << G4BestUnit(analysisManager->GetH1(1)->rms(),  "Energy") << G4endl;
       
        G4cout << " Eshape3 : mean = "
       << G4BestUnit(analysisManager->GetH1(2)->mean(), "Energy")
       << " rms = "
       << G4BestUnit(analysisManager->GetH1(2)->rms(),  "Energy") << G4endl;
       
        G4cout << " Eshape4 : mean = "
       << G4BestUnit(analysisManager->GetH1(3)->mean(), "Energy")
       << " rms = "
       << G4BestUnit(analysisManager->GetH1(3)->rms(),  "Energy") << G4endl;
       
        G4cout << " Eshape5 : mean = "
       << G4BestUnit(analysisManager->GetH1(4)->mean(), "Energy")
       << " rms = "
       << G4BestUnit(analysisManager->GetH1(4)->rms(),  "Energy") << G4endl;
       
       

    

    G4cout << " Lshape1 : mean = "
      << G4BestUnit(analysisManager->GetH1(5)->mean(), "Length")
      << " rms = "
      << G4BestUnit(analysisManager->GetH1(5)->rms(),  "Length") << G4endl;
      
      
          G4cout << " Lshape2 : mean = "
      << G4BestUnit(analysisManager->GetH1(6)->mean(), "Length")
      << " rms = "
      << G4BestUnit(analysisManager->GetH1(6)->rms(),  "Length") << G4endl;
      
          G4cout << " Lshape3 : mean = "
      << G4BestUnit(analysisManager->GetH1(7)->mean(), "Length")
      << " rms = 8
      << G4BestUnit(analysisManager->GetH1(7)->rms(),  "Length") << G4endl;
      
          G4cout << " Lshape4 : mean = "
      << G4BestUnit(analysisManager->GetH1(8)->mean(), "Length")
      << " rms = "
      << G4BestUnit(analysisManager->GetH1(8)->rms(),  "Length") << G4endl;
      
          G4cout << " Lshape5 : mean = "
      << G4BestUnit(analysisManager->GetH1(9)->mean(), "Length")
      << " rms = "
      << G4BestUnit(analysisManager->GetH1(9)->rms(),  "Length") << G4endl;
      
      

           
  }

  // save histograms & ntuple
  //
  analysisManager->Write();
  analysisManager->CloseFile();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

}
