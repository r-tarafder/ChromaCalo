#ifndef ActionInitialization_HH
#define ActionInitialization_HH

#include "G4VUserActionInitialization.hh"


namespace upo
{
  class DetectorConstruction;
}

namespace upo
{

/// Action initialization class.

class ActionInitialization : public G4VUserActionInitialization
{
  public:
    ActionInitialization(B4::DetectorConstruction*);
    ~ActionInitialization() override = default;

    void BuildForMaster() const override;
    void Build() const override;

  private:
    upo::DetectorConstruction* fDetConstruction = nullptr;
};

}

#endif


