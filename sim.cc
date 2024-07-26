#include <iostream>

#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "G4VisManager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"
#include "G4UIterminal.hh"
#include "construction.hh"
#include "MySteppingAction.hh"
#include "MyEventAction.hh"
#include "physics.hh"
#include "action.hh"


int main(int argc, char** argv)
{

    // Instantiate the run manager
    G4RunManager *runManager = new G4RunManager();
    
    
    // Set up user initialization classes
    runManager->SetUserInitialization(new MyDetectorConstruction());
    runManager->SetUserInitialization(new MyPhysicsList());
    
    
    
    // Set user action classes
    MySteppingAction* steppingAction = new MySteppingAction();
    runManager->SetUserAction(new MyPrimaryGenerator());
    runManager->SetUserAction(steppingAction);
    runManager->SetUserAction(new MyEventAction(steppingAction));
    
    // Initialize Geant4 kernel
    runManager->Initialize();
    
    
    // Start the UI session
    G4UIExecutive *ui = new G4UIExecutive(argc, argv);
   
    G4VisManager *visManager = new G4VisExecutive();
    visManager->Initialize();
   
    G4UImanager *UImanager = G4UImanager::GetUIpointer();
    
    UImanager->ApplyCommand("/vis/open OGL");
    UImanager->ApplyCommand("/vis/viewer/set/viewpointVector 1 1 1");
    UImanager->ApplyCommand("/vis/drawVolume");
    UImanager->ApplyCommand("/vis/viewer/set/autoRefresh true");
    UImanager->ApplyCommand("/vis/scene/add/trajectories smooth");
    G4UImanager::GetUIpointer()->ApplyCommand("/control/execute init_vis.mac");
    ui->SessionStart();
   
    ui->SessionStart();
    delete ui;
   
    delete runManager;
    return 0;
}
