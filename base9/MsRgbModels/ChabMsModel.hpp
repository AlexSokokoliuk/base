#ifndef GCHABMAG_H
#define GCHABMAG_H

#include <string>
#include <vector>

#include "../MsRgbModel.hpp"

const int N_CHAB_FILTS     = 8;
const int N_CHAB_Z         = 4;    /* number of metallicities in Chaboyer-Dotter isochrones */
const int N_CHAB_Y         = 5;    /* number of He abundances in Chaboyer-Dotter isochrones */
const int N_CHAB_AGES      = 19;   /* number of ages in Chaboyer-Dotter isochonres */
const int MAX_CHAB_ENTRIES = 280;

class ChabMsModel : public MsRgbModel
{
  public:
    ChabMsModel() {;}
    virtual ~ChabMsModel() {;}

    virtual bool isSupported(FilterSetName) const;

  protected:
    virtual int numFilts() const { return N_CHAB_FILTS; }
    virtual std::string getFileName (std::string) const;
};

#endif
