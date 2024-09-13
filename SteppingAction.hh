#ifndef STEPPING_ACTION_HH
#define STEPPING_ACTION_HH

#include "G4UserSteppingAction.hh"
#include "globals.hh"

/*class TFile;
class TTree;

class SteppingAction : public G4UserSteppingAction {
public:
    SteppingAction();
    virtual ~SteppingAction();

    virtual void UserSteppingAction(const G4Step* step);

private:
    TFile* fRootFile;
    TTree* fTree;
    G4double fEdep[5];
};

#endif
*/
namespace upo
{
  class DetectorConstruction;
}

namespace upo
{

class EventAction;

/// Stepping action class.
///
/// In UserSteppingAction() there are collected the energy deposit and track
/// lengths of charged particles in Absober and Gap layers and
/// updated in EventAction.

class SteppingAction : public G4UserSteppingAction
{
public:
  SteppingAction(const upo::DetectorConstruction* detConstruction,
                 EventAction* eventAction);
  ~SteppingAction() override = default;

  void UserSteppingAction(const G4Step* step) override;

private:
  const upo::DetectorConstruction* fDetConstruction = nullptr;
  EventAction* fEventAction = nullptr;
};

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
