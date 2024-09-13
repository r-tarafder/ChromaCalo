#ifndef EventAction_HH
#define EventAction_HH

#include "G4UserEventAction.hh"
#include "globals.hh"

namespace upo
{

/// Event action class
///
/// It defines data members to hold the energy deposit and track lengths
/// of charged particles in Absober and Gap layers:
/// - fEnergyAbs, fEnergyGap, fTrackLAbs, fTrackLGap
/// which are collected step by step via the functions
/// - AddAbs(), AddGap()

class EventAction : public G4UserEventAction
{
  public:
    EventAction() = default;
    ~EventAction() override = default;

    void  BeginOfEventAction(const G4Event* event) override;
    void    EndOfEventAction(const G4Event* event) override;

    void Addshape1(G4double de, G4double dl);
    void Addshape2(G4double de, G4double dl);
    void Addshape3(G4double de, G4double dl);
    void Addshape4(G4double de, G4double dl);
    void Addshape5(G4double de, G4double dl);

  private:
    G4double  fEnergyshape1 = 0.;
    G4double  fEnergyshape2 = 0.;
    G4double  fEnergyshape2 = 0.;
    G4double  fEnergyshape2 = 0.;
    G4double  fEnergyshape2 = 0.;
    
   G4double  fTrackLshape1 = 0.;
   G4double  fTrackLshape1 = 0.;
   G4double  fTrackLshape1 = 0.;
   G4double  fTrackLshape1 = 0.;
   G4double  fTrackLshape1 = 0.;
};

// inline functions

inline void EventAction::Addshape1(G4double de, G4double dl) {
  fEnergyshape1 += de;
  fTrackLshape1 += dl;
}

inline void EventAction::Addshape2(G4double de, G4double dl) {
  fEnergyshape2 += de;
  fTrackLshape2 += dl;
}

inline void EventAction::Addshape3(G4double de, G4double dl) {
  fEnergyshape3 += de;
  fTrackLshape3 += dl;
}

inline void EventAction::Addshape4(G4double de, G4double dl) {
  fEnergyshape4 += de;
  fTrackLshape4 += dl;
}

inline void EventAction::Addshape5(G4double de, G4double dl) {
  fEnergyshape5 += de;
  fTrackLshape5 += dl;
}

}
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

