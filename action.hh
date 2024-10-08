/*#ifndef ACTION_HH
#define ACTION_HH
#include "G4VUserActionInitialization.hh"
#include "generator.hh"
class MyActionInitialization : public G4VUserActionInitialization
{
public:
MyActionInitialization();
 ~MyActionInitialization();
virtual void Build() const;
};
#endif
*/

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
    ActionInitialization(upo::DetectorConstruction*);
    ~ActionInitialization() override = default;

    void BuildForMaster() const override;
    void Build() const override;

  private:
    upo::DetectorConstruction* fDetConstruction = nullptr;
};

}

#endif

