#include "EventAction.hh"
#include "action.hh"

#include "G4AnalysisManager.hh"
#include "G4RunManager.hh"
#include "G4Event.hh"
#include "G4UnitsTable.hh"

#include "Randomize.hh"
#include <iomanip>

namespace upo
{

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void EventAction::BeginOfEventAction(const G4Event* /*event*/)
{
  // initialisation per event
      fEnergyshape1 = 0.;
      fEnergyshape2 = 0.;
      fEnergyshape2 = 0.;
      fEnergyshape2 = 0.;
      fEnergyshape2 = 0.;
    
    fTrackLshape1 = 0.;
    fTrackLshape1 = 0.;
    fTrackLshape1 = 0.;
    fTrackLshape1 = 0.;
    fTrackLshape1 = 0.;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void EventAction::EndOfEventAction(const G4Event* event)
{
  // get analysis manager
  auto analysisManager = G4AnalysisManager::Instance();

  // fill histograms
  analysisManager->FillH1(0,  fEnergyshape1);
  analysisManager->FillH1(1,  fEnergyshape1);
  analysisManager->FillH1(2,  fEnergyshape1);
  analysisManager->FillH1(3,  fEnergyshape1);
  analysisManager->FillH1(4,  fEnergyshape1);
  
  analysisManager->FillH1(5, fTrackLshape1);
  analysisManager->FillH1(6, fTrackLshape1);
  analysisManager->FillH1(7, fTrackLshape1);
  analysisManager->FillH1(8, fTrackLshape1);
  analysisManager->FillH1(9, fTrackLshape1);

  // fill ntuple
  analysisManager->FillNtupleDColumn(0, fEnergyshape1);
  analysisManager->FillNtupleDColumn(1, fEnergyshape1);
  analysisManager->FillNtupleDColumn(2, fEnergyshape1);
  analysisManager->FillNtupleDColumn(3, fEnergyshape1);
  analysisManager->FillNtupleDColumn(4, fEnergyshape1);
  
 analysisManager->FillNtupleDColumn(5, fTrackLshape1);
 analysisManager->FillNtupleDColumn(6, fTrackLshape1);
 analysisManager->FillNtupleDColumn(7, fTrackLshape1);
 analysisManager->FillNtupleDColumn(8, fTrackLshape1);
 analysisManager->FillNtupleDColumn(9, fTrackLshape1);
 analysisManager->AddNtupleRow();

  // Print per event (modulo n)
  //
  auto eventID = event->GetEventID();
  auto printModulo = G4RunManager::GetRunManager()->GetPrintProgress();
  if ( ( printModulo > 0 ) && ( eventID % printModulo == 0 ) ) {
    G4cout
       << "       shape1: energy: " << std::setw(7)
                                        << G4BestUnit(fEnergyshape1,"Energy")
       << "       total track length: " << std::setw(7)
                                        << G4BestUnit(fTrackLshape1,"Length")
       << G4endl
      
      << "       shape2: energy: " << std::setw(7)
                                        << G4BestUnit(fEnergyshape2,"Energy")
       << "       total track length: " << std::setw(7)
                                        << G4BestUnit(fTrackLshape2,"Length")
       << G4endl
       
       << "       shape3: energy: " << std::setw(7)
                                        << G4BestUnit(fEnergyshape3,"Energy")
       << "       total track length: " << std::setw(7)
                                        << G4BestUnit(fTrackLshape3,"Length")
       << G4endl
       
       << "       shape4: energy: " << std::setw(7)
                                        << G4BestUnit(fEnergyshape4,"Energy")
       << "       total track length: " << std::setw(7)
                                        << G4BestUnit(fTrackLshape4,"Length")
       << G4endl
       
       << "       shape5: energy: " << std::setw(7)
                                        << G4BestUnit(fEnergyshape5,"Energy")
       << "       total track length: " << std::setw(7)
                                        << G4BestUnit(fTrackLshape5,"Length")
       << G4endl;
       
    G4cout << "--> End of event " << eventID << "\n" << G4endl;       
  }
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo.....

} 
