/// \file    ArgoNeuTRecoBaseDrawer.h
/// \brief   Class to aid in the rendering of ArgoNeuT Reconstruction objects
/// \author  msoderbe@syr.edu
#ifndef EVD_ARGONEUTRECOBASEDRAWER_H
#define EVD_ARGONEUTRECOBASEDRAWER_H
#include "EventDisplay/RecoBaseDrawer.h"
#include <vector>
#ifdef __CINT__
namespace art { 
  class Event;
  class PtrVector;
  class Ptr;
}
#else
#include "art/Persistency/Common/PtrVector.h"
#endif

namespace t962     { class MINOS; class MINOSTrackMatch; }

namespace argoevd {
  /// Aid in the rendering of ArgoNeuT Reconstruction objects
   class ArgoneutRecoBaseDrawer : public evd::RecoBaseDrawer {
  public:
    ArgoneutRecoBaseDrawer();
    ~ArgoneutRecoBaseDrawer();

  public:

     void ArgoSpacePoint(const recob::Prong* prong,
                         int                 id,
                         evdb::View3D*       view,
                         bool matched=false,
                         float charge=-999.);
     
     void ArgoProng3D(const art::Event& evt,
                      evdb::View3D*     view);

    
  private:

    int GetArgoProngs(const art::Event&                 evt,
                      const std::string&                which,
                      std::vector<const recob::Prong*>& prong);


     int GetMinos(const art::Event&            evt,
                  const std::string&           which,
                  art::PtrVector<t962::MINOS>& minos);

     int GetMinosTrackMatch(const art::Event&            evt,
                            const std::string&           which,
                            art::PtrVector<t962::MINOSTrackMatch>& minosmatch);

    
        
    
    
  };
}

#endif
////////////////////////////////////////////////////////////////////////