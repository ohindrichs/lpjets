#ifndef URStreamer_h
#define URStreamer_h

//#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include "TLorentzVector.h"
#include <vector>
using namespace std;

class Met: public TLorentzVector{
friend class URStreamer;
public:
//  Met(const float &i_pxunc_,const float &i_pyunc_):
//    
//  {}
  Met():
    TLorentzVector(),
    pxunc_(0),
    pyunc_(0)
  {}
  float pxunc() const {return pxunc_;}
  float pyunc() const {return pyunc_;}
  ClassDef(Met, 1);
private:
  float pxunc_;
  float pyunc_;
  void setpxunc(const float value) {pxunc_ = value;}
  void setpyunc(const float value) {pyunc_ = value;}
  void setLotentzVector(float px, float py){SetXYZM(px, py, 0., 0.);}
};

class Pl: public TLorentzVector{
friend class URStreamer;
public:
//  Pl(const int &i_charge_,const int &i_pdgId_,const int &i_status_,const float &i_isoR3_,const float &i_isoR4_):
//    
//  {}
  Pl():
    TLorentzVector(),
    charge_(0),
    pdgId_(0),
    status_(0),
    isoR3_(0),
    isoR4_(0)
  {}
  int charge() const {return charge_;}
  int pdgId() const {return pdgId_;}
  int status() const {return status_;}
  float isoR3() const {return isoR3_;}
  float isoR4() const {return isoR4_;}
  ClassDef(Pl, 1);
private:
  int charge_;
  int pdgId_;
  int status_;
  float isoR3_;
  float isoR4_;
  void setcharge(const int value) {charge_ = value;}
  void setpdgId(const int value) {pdgId_ = value;}
  void setstatus(const int value) {status_ = value;}
  void setisoR3(const float value) {isoR3_ = value;}
  void setisoR4(const float value) {isoR4_ = value;}
  void setLotentzVector(float pt, float eta, float phi, float e){SetPtEtaPhiE(pt, eta, phi, e);}
};

class Mcweight{
friend class URStreamer;
public:
//  Mcweight(const float &i_weights_):
//    
//  {}
  Mcweight():
    weights_(0)
  {}
  float weights() const {return weights_;}
private:
  float weights_;
  void setweights(const float value) {weights_ = value;}
};

class Geninfo{
friend class URStreamer;
public:
//  Geninfo(const Float_t &i_weight_,const Float_t &i_pdfid1_,const Float_t &i_pdfid2_,const Float_t &i_x1_,const Float_t &i_x2_,const Float_t &i_renScale_):
//    
//  {}
  Geninfo():
    weight_(0),
    pdfid1_(0),
    pdfid2_(0),
    x1_(0),
    x2_(0),
    renScale_(0)
  {}
  Float_t weight() const {return weight_;}
  Float_t pdfid1() const {return pdfid1_;}
  Float_t pdfid2() const {return pdfid2_;}
  Float_t x1() const {return x1_;}
  Float_t x2() const {return x2_;}
  Float_t renScale() const {return renScale_;}
private:
  Float_t weight_;
  Float_t pdfid1_;
  Float_t pdfid2_;
  Float_t x1_;
  Float_t x2_;
  Float_t renScale_;
  void setweight(const Float_t value) {weight_ = value;}
  void setpdfid1(const Float_t value) {pdfid1_ = value;}
  void setpdfid2(const Float_t value) {pdfid2_ = value;}
  void setx1(const Float_t value) {x1_ = value;}
  void setx2(const Float_t value) {x2_ = value;}
  void setrenScale(const Float_t value) {renScale_ = value;}
};

class Photon: public TLorentzVector{
friend class URStreamer;
public:
//  Photon(const int &i_charge_,const float &i_x_,const float &i_y_,const float &i_z_,const float &i_energy_,const float &i_rawEnergy_,const float &i_phiWidth_,const float &i_etaWidth_,const float &i_e3x3_,const float &i_maxCrystalEnergy_,const bool &i_isEB_,const bool &i_isEE_,const bool &i_isPFlowPhoton_,const bool &i_hasConversionTracks_,const bool &i_hasPixelSeed_):
//    
//  {}
  Photon():
    TLorentzVector(),
    charge_(0),
    x_(0),
    y_(0),
    z_(0),
    energy_(0),
    rawEnergy_(0),
    phiWidth_(0),
    etaWidth_(0),
    e3x3_(0),
    maxCrystalEnergy_(0),
    isEB_(0),
    isEE_(0),
    isPFlowPhoton_(0),
    hasConversionTracks_(0),
    hasPixelSeed_(0)
  {}
  int charge() const {return charge_;}
  float x() const {return x_;}
  float y() const {return y_;}
  float z() const {return z_;}
  float energy() const {return energy_;}
  float rawEnergy() const {return rawEnergy_;}
  float phiWidth() const {return phiWidth_;}
  float etaWidth() const {return etaWidth_;}
  float e3x3() const {return e3x3_;}
  float maxCrystalEnergy() const {return maxCrystalEnergy_;}
  bool isEB() const {return isEB_;}
  bool isEE() const {return isEE_;}
  bool isPFlowPhoton() const {return isPFlowPhoton_;}
  bool hasConversionTracks() const {return hasConversionTracks_;}
  bool hasPixelSeed() const {return hasPixelSeed_;}
  ClassDef(Photon, 1);
private:
  int charge_;
  float x_;
  float y_;
  float z_;
  float energy_;
  float rawEnergy_;
  float phiWidth_;
  float etaWidth_;
  float e3x3_;
  float maxCrystalEnergy_;
  bool isEB_;
  bool isEE_;
  bool isPFlowPhoton_;
  bool hasConversionTracks_;
  bool hasPixelSeed_;
  void setcharge(const int value) {charge_ = value;}
  void setx(const float value) {x_ = value;}
  void sety(const float value) {y_ = value;}
  void setz(const float value) {z_ = value;}
  void setenergy(const float value) {energy_ = value;}
  void setrawEnergy(const float value) {rawEnergy_ = value;}
  void setphiWidth(const float value) {phiWidth_ = value;}
  void setetaWidth(const float value) {etaWidth_ = value;}
  void sete3x3(const float value) {e3x3_ = value;}
  void setmaxCrystalEnergy(const float value) {maxCrystalEnergy_ = value;}
  void setisEB(const bool value) {isEB_ = value;}
  void setisEE(const bool value) {isEE_ = value;}
  void setisPFlowPhoton(const bool value) {isPFlowPhoton_ = value;}
  void sethasConversionTracks(const bool value) {hasConversionTracks_ = value;}
  void sethasPixelSeed(const bool value) {hasPixelSeed_ = value;}
  void setLotentzVector(float pt, float eta, float phi, float e){SetPtEtaPhiE(pt, eta, phi, e);}
};

class Ttgen: public TLorentzVector{
friend class URStreamer;
public:
//  Ttgen(const int &i_charge_,const int &i_pdgId_,const int &i_status_):
//    
//  {}
  Ttgen():
    TLorentzVector(),
    charge_(0),
    pdgId_(0),
    status_(0)
  {}
  int charge() const {return charge_;}
  int pdgId() const {return pdgId_;}
  int status() const {return status_;}
  ClassDef(Ttgen, 1);
private:
  int charge_;
  int pdgId_;
  int status_;
  void setcharge(const int value) {charge_ = value;}
  void setpdgId(const int value) {pdgId_ = value;}
  void setstatus(const int value) {status_ = value;}
  void setLotentzVector(float pt, float eta, float phi, float e){SetPtEtaPhiE(pt, eta, phi, e);}
};

class Filter{
friend class URStreamer;
public:
//  Filter(const Int_t &i_Flag_goodVertices_,const Int_t &i_Flag_CSCTightHaloFilter_,const Int_t &i_Flag_trkPOGFilters_,const Int_t &i_Flag_trkPOG_logErrorTooManyClusters_,const Int_t &i_Flag_EcalDeadCellTriggerPrimitiveFilter_,const Int_t &i_Flag_ecalLaserCorrFilter_,const Int_t &i_Flag_trkPOG_manystripclus53X_,const Int_t &i_Flag_eeBadScFilter_,const Int_t &i_Flag_METFilters_,const Int_t &i_Flag_HBHENoiseFilter_,const Int_t &i_Flag_trkPOG_toomanystripclus53X_,const Int_t &i_Flag_hcalLaserEventFilter_):
//    
//  {}
  Filter():
    Flag_goodVertices_(0),
    Flag_CSCTightHaloFilter_(0),
    Flag_trkPOGFilters_(0),
    Flag_trkPOG_logErrorTooManyClusters_(0),
    Flag_EcalDeadCellTriggerPrimitiveFilter_(0),
    Flag_ecalLaserCorrFilter_(0),
    Flag_trkPOG_manystripclus53X_(0),
    Flag_eeBadScFilter_(0),
    Flag_METFilters_(0),
    Flag_HBHENoiseFilter_(0),
    Flag_trkPOG_toomanystripclus53X_(0),
    Flag_hcalLaserEventFilter_(0)
  {}
  Int_t Flag_goodVertices() const {return Flag_goodVertices_;}
  Int_t Flag_CSCTightHaloFilter() const {return Flag_CSCTightHaloFilter_;}
  Int_t Flag_trkPOGFilters() const {return Flag_trkPOGFilters_;}
  Int_t Flag_trkPOG_logErrorTooManyClusters() const {return Flag_trkPOG_logErrorTooManyClusters_;}
  Int_t Flag_EcalDeadCellTriggerPrimitiveFilter() const {return Flag_EcalDeadCellTriggerPrimitiveFilter_;}
  Int_t Flag_ecalLaserCorrFilter() const {return Flag_ecalLaserCorrFilter_;}
  Int_t Flag_trkPOG_manystripclus53X() const {return Flag_trkPOG_manystripclus53X_;}
  Int_t Flag_eeBadScFilter() const {return Flag_eeBadScFilter_;}
  Int_t Flag_METFilters() const {return Flag_METFilters_;}
  Int_t Flag_HBHENoiseFilter() const {return Flag_HBHENoiseFilter_;}
  Int_t Flag_trkPOG_toomanystripclus53X() const {return Flag_trkPOG_toomanystripclus53X_;}
  Int_t Flag_hcalLaserEventFilter() const {return Flag_hcalLaserEventFilter_;}
private:
  Int_t Flag_goodVertices_;
  Int_t Flag_CSCTightHaloFilter_;
  Int_t Flag_trkPOGFilters_;
  Int_t Flag_trkPOG_logErrorTooManyClusters_;
  Int_t Flag_EcalDeadCellTriggerPrimitiveFilter_;
  Int_t Flag_ecalLaserCorrFilter_;
  Int_t Flag_trkPOG_manystripclus53X_;
  Int_t Flag_eeBadScFilter_;
  Int_t Flag_METFilters_;
  Int_t Flag_HBHENoiseFilter_;
  Int_t Flag_trkPOG_toomanystripclus53X_;
  Int_t Flag_hcalLaserEventFilter_;
  void setFlag_goodVertices(const Int_t value) {Flag_goodVertices_ = value;}
  void setFlag_CSCTightHaloFilter(const Int_t value) {Flag_CSCTightHaloFilter_ = value;}
  void setFlag_trkPOGFilters(const Int_t value) {Flag_trkPOGFilters_ = value;}
  void setFlag_trkPOG_logErrorTooManyClusters(const Int_t value) {Flag_trkPOG_logErrorTooManyClusters_ = value;}
  void setFlag_EcalDeadCellTriggerPrimitiveFilter(const Int_t value) {Flag_EcalDeadCellTriggerPrimitiveFilter_ = value;}
  void setFlag_ecalLaserCorrFilter(const Int_t value) {Flag_ecalLaserCorrFilter_ = value;}
  void setFlag_trkPOG_manystripclus53X(const Int_t value) {Flag_trkPOG_manystripclus53X_ = value;}
  void setFlag_eeBadScFilter(const Int_t value) {Flag_eeBadScFilter_ = value;}
  void setFlag_METFilters(const Int_t value) {Flag_METFilters_ = value;}
  void setFlag_HBHENoiseFilter(const Int_t value) {Flag_HBHENoiseFilter_ = value;}
  void setFlag_trkPOG_toomanystripclus53X(const Int_t value) {Flag_trkPOG_toomanystripclus53X_ = value;}
  void setFlag_hcalLaserEventFilter(const Int_t value) {Flag_hcalLaserEventFilter_ = value;}
};

class Trigger{
friend class URStreamer;
public:
//  Trigger(const Int_t &i_HLT_notexists_,const Int_t &i_HLT_IsoTkMu24_,const Int_t &i_HLT_IsoMu24_,const Int_t &i_HLT_IsoTkMu27_,const Int_t &i_HLT_IsoMu27_,const Int_t &i_HLT_Ele27_eta2p1_WPTight_Gsf_,const Int_t &i_HLT_Ele32_eta2p1_WPTight_Gsf_,const Int_t &i_HLT_Ele32_WPTight_Gsf_,const Int_t &i_HLT_Ele27_WPTight_Gsf_,const Int_t &i_L1_SingleIsoEG34er_,const Int_t &i_L1_SingleIsoEG34_,const Int_t &i_L1_SingleIsoEG32er_,const Int_t &i_L1_SingleIsoEG32_,const Int_t &i_PSColumn_,const Int_t &i_El27ptmax_):
//    
//  {}
  Trigger():
    HLT_notexists_(0),
    HLT_IsoTkMu24_(0),
    HLT_IsoMu24_(0),
    HLT_IsoTkMu27_(0),
    HLT_IsoMu27_(0),
    HLT_Ele27_eta2p1_WPTight_Gsf_(0),
    HLT_Ele32_eta2p1_WPTight_Gsf_(0),
    HLT_Ele32_WPTight_Gsf_(0),
    HLT_Ele27_WPTight_Gsf_(0),
    L1_SingleIsoEG34er_(0),
    L1_SingleIsoEG34_(0),
    L1_SingleIsoEG32er_(0),
    L1_SingleIsoEG32_(0),
    PSColumn_(0),
    El27ptmax_(0)
  {}
  Int_t HLT_notexists() const {return HLT_notexists_;}
  Int_t HLT_IsoTkMu24() const {return HLT_IsoTkMu24_;}
  Int_t HLT_IsoMu24() const {return HLT_IsoMu24_;}
  Int_t HLT_IsoTkMu27() const {return HLT_IsoTkMu27_;}
  Int_t HLT_IsoMu27() const {return HLT_IsoMu27_;}
  Int_t HLT_Ele27_eta2p1_WPTight_Gsf() const {return HLT_Ele27_eta2p1_WPTight_Gsf_;}
  Int_t HLT_Ele32_eta2p1_WPTight_Gsf() const {return HLT_Ele32_eta2p1_WPTight_Gsf_;}
  Int_t HLT_Ele32_WPTight_Gsf() const {return HLT_Ele32_WPTight_Gsf_;}
  Int_t HLT_Ele27_WPTight_Gsf() const {return HLT_Ele27_WPTight_Gsf_;}
  Int_t L1_SingleIsoEG34er() const {return L1_SingleIsoEG34er_;}
  Int_t L1_SingleIsoEG34() const {return L1_SingleIsoEG34_;}
  Int_t L1_SingleIsoEG32er() const {return L1_SingleIsoEG32er_;}
  Int_t L1_SingleIsoEG32() const {return L1_SingleIsoEG32_;}
  Int_t PSColumn() const {return PSColumn_;}
  Int_t El27ptmax() const {return El27ptmax_;}
private:
  Int_t HLT_notexists_;
  Int_t HLT_IsoTkMu24_;
  Int_t HLT_IsoMu24_;
  Int_t HLT_IsoTkMu27_;
  Int_t HLT_IsoMu27_;
  Int_t HLT_Ele27_eta2p1_WPTight_Gsf_;
  Int_t HLT_Ele32_eta2p1_WPTight_Gsf_;
  Int_t HLT_Ele32_WPTight_Gsf_;
  Int_t HLT_Ele27_WPTight_Gsf_;
  Int_t L1_SingleIsoEG34er_;
  Int_t L1_SingleIsoEG34_;
  Int_t L1_SingleIsoEG32er_;
  Int_t L1_SingleIsoEG32_;
  Int_t PSColumn_;
  Int_t El27ptmax_;
  void setHLT_notexists(const Int_t value) {HLT_notexists_ = value;}
  void setHLT_IsoTkMu24(const Int_t value) {HLT_IsoTkMu24_ = value;}
  void setHLT_IsoMu24(const Int_t value) {HLT_IsoMu24_ = value;}
  void setHLT_IsoTkMu27(const Int_t value) {HLT_IsoTkMu27_ = value;}
  void setHLT_IsoMu27(const Int_t value) {HLT_IsoMu27_ = value;}
  void setHLT_Ele27_eta2p1_WPTight_Gsf(const Int_t value) {HLT_Ele27_eta2p1_WPTight_Gsf_ = value;}
  void setHLT_Ele32_eta2p1_WPTight_Gsf(const Int_t value) {HLT_Ele32_eta2p1_WPTight_Gsf_ = value;}
  void setHLT_Ele32_WPTight_Gsf(const Int_t value) {HLT_Ele32_WPTight_Gsf_ = value;}
  void setHLT_Ele27_WPTight_Gsf(const Int_t value) {HLT_Ele27_WPTight_Gsf_ = value;}
  void setL1_SingleIsoEG34er(const Int_t value) {L1_SingleIsoEG34er_ = value;}
  void setL1_SingleIsoEG34(const Int_t value) {L1_SingleIsoEG34_ = value;}
  void setL1_SingleIsoEG32er(const Int_t value) {L1_SingleIsoEG32er_ = value;}
  void setL1_SingleIsoEG32(const Int_t value) {L1_SingleIsoEG32_ = value;}
  void setPSColumn(const Int_t value) {PSColumn_ = value;}
  void setEl27ptmax(const Int_t value) {El27ptmax_ = value;}
};

class Electron: public TLorentzVector{
friend class URStreamer;
public:
//  Electron(const int &i_charge_,const float &i_dB_,const float &i_ipDXY_,const float &i_dz_,const float &i_nMissingInnerHits_,const float &i_SCeta_,const float &i_DEtaSCTrk_,const float &i_DPhiSCTrk_,const float &i_ESCOverETrack_,const float &i_ecalEnergy_,const float &i_full5x5_sigmaIEtaIEta_,const float &i_hadronicOverEM_,const bool &i_isEB_,const bool &i_isEE_,const float &i_pfChargedIso_,const float &i_pfNeutralIso_,const float &i_pfPhotonIso_,const float &i_pfPUIso_,const bool &i_HLT_Ele27_eta2p1_WPTight_Gsf_,const bool &i_HLT_Ele32_eta2p1_WPTight_Gsf_,const bool &i_HLT_Ele32_WPTight_Gsf_,const bool &i_HLT_Ele27_WPTight_Gsf_,const bool &i_conversion_):
//    
//  {}
  Electron():
    TLorentzVector(),
    charge_(0),
    dB_(0),
    ipDXY_(0),
    dz_(0),
    nMissingInnerHits_(0),
    SCeta_(0),
    DEtaSCTrk_(0),
    DPhiSCTrk_(0),
    ESCOverETrack_(0),
    ecalEnergy_(0),
    full5x5_sigmaIEtaIEta_(0),
    hadronicOverEM_(0),
    isEB_(0),
    isEE_(0),
    pfChargedIso_(0),
    pfNeutralIso_(0),
    pfPhotonIso_(0),
    pfPUIso_(0),
    HLT_Ele27_eta2p1_WPTight_Gsf_(0),
    HLT_Ele32_eta2p1_WPTight_Gsf_(0),
    HLT_Ele32_WPTight_Gsf_(0),
    HLT_Ele27_WPTight_Gsf_(0),
    conversion_(0)
  {}
  int charge() const {return charge_;}
  float dB() const {return dB_;}
  float ipDXY() const {return ipDXY_;}
  float dz() const {return dz_;}
  float nMissingInnerHits() const {return nMissingInnerHits_;}
  float SCeta() const {return SCeta_;}
  float DEtaSCTrk() const {return DEtaSCTrk_;}
  float DPhiSCTrk() const {return DPhiSCTrk_;}
  float ESCOverETrack() const {return ESCOverETrack_;}
  float ecalEnergy() const {return ecalEnergy_;}
  float full5x5_sigmaIEtaIEta() const {return full5x5_sigmaIEtaIEta_;}
  float hadronicOverEM() const {return hadronicOverEM_;}
  bool isEB() const {return isEB_;}
  bool isEE() const {return isEE_;}
  float pfChargedIso() const {return pfChargedIso_;}
  float pfNeutralIso() const {return pfNeutralIso_;}
  float pfPhotonIso() const {return pfPhotonIso_;}
  float pfPUIso() const {return pfPUIso_;}
  bool HLT_Ele27_eta2p1_WPTight_Gsf() const {return HLT_Ele27_eta2p1_WPTight_Gsf_;}
  bool HLT_Ele32_eta2p1_WPTight_Gsf() const {return HLT_Ele32_eta2p1_WPTight_Gsf_;}
  bool HLT_Ele32_WPTight_Gsf() const {return HLT_Ele32_WPTight_Gsf_;}
  bool HLT_Ele27_WPTight_Gsf() const {return HLT_Ele27_WPTight_Gsf_;}
  bool conversion() const {return conversion_;}
  ClassDef(Electron, 1);
private:
  int charge_;
  float dB_;
  float ipDXY_;
  float dz_;
  float nMissingInnerHits_;
  float SCeta_;
  float DEtaSCTrk_;
  float DPhiSCTrk_;
  float ESCOverETrack_;
  float ecalEnergy_;
  float full5x5_sigmaIEtaIEta_;
  float hadronicOverEM_;
  bool isEB_;
  bool isEE_;
  float pfChargedIso_;
  float pfNeutralIso_;
  float pfPhotonIso_;
  float pfPUIso_;
  bool HLT_Ele27_eta2p1_WPTight_Gsf_;
  bool HLT_Ele32_eta2p1_WPTight_Gsf_;
  bool HLT_Ele32_WPTight_Gsf_;
  bool HLT_Ele27_WPTight_Gsf_;
  bool conversion_;
  void setcharge(const int value) {charge_ = value;}
  void setdB(const float value) {dB_ = value;}
  void setipDXY(const float value) {ipDXY_ = value;}
  void setdz(const float value) {dz_ = value;}
  void setnMissingInnerHits(const float value) {nMissingInnerHits_ = value;}
  void setSCeta(const float value) {SCeta_ = value;}
  void setDEtaSCTrk(const float value) {DEtaSCTrk_ = value;}
  void setDPhiSCTrk(const float value) {DPhiSCTrk_ = value;}
  void setESCOverETrack(const float value) {ESCOverETrack_ = value;}
  void setecalEnergy(const float value) {ecalEnergy_ = value;}
  void setfull5x5_sigmaIEtaIEta(const float value) {full5x5_sigmaIEtaIEta_ = value;}
  void sethadronicOverEM(const float value) {hadronicOverEM_ = value;}
  void setisEB(const bool value) {isEB_ = value;}
  void setisEE(const bool value) {isEE_ = value;}
  void setpfChargedIso(const float value) {pfChargedIso_ = value;}
  void setpfNeutralIso(const float value) {pfNeutralIso_ = value;}
  void setpfPhotonIso(const float value) {pfPhotonIso_ = value;}
  void setpfPUIso(const float value) {pfPUIso_ = value;}
  void setHLT_Ele27_eta2p1_WPTight_Gsf(const bool value) {HLT_Ele27_eta2p1_WPTight_Gsf_ = value;}
  void setHLT_Ele32_eta2p1_WPTight_Gsf(const bool value) {HLT_Ele32_eta2p1_WPTight_Gsf_ = value;}
  void setHLT_Ele32_WPTight_Gsf(const bool value) {HLT_Ele32_WPTight_Gsf_ = value;}
  void setHLT_Ele27_WPTight_Gsf(const bool value) {HLT_Ele27_WPTight_Gsf_ = value;}
  void setconversion(const bool value) {conversion_ = value;}
  void setLotentzVector(float pt, float eta, float phi, float e){SetPtEtaPhiE(pt, eta, phi, e);}
};

class Rho{
friend class URStreamer;
public:
//  Rho(const Double_t &i_value_):
//    
//  {}
  Rho():
    value_(0)
  {}
  Double_t value() const {return value_;}
private:
  Double_t value_;
  void setvalue(const Double_t value) {value_ = value;}
};

class Rivetpl: public TLorentzVector{
friend class URStreamer;
public:
//  Rivetpl(const int &i_charge_,const int &i_pdgId_,const int &i_status_):
//    
//  {}
  Rivetpl():
    TLorentzVector(),
    charge_(0),
    pdgId_(0),
    status_(0)
  {}
  int charge() const {return charge_;}
  int pdgId() const {return pdgId_;}
  int status() const {return status_;}
  ClassDef(Rivetpl, 1);
private:
  int charge_;
  int pdgId_;
  int status_;
  void setcharge(const int value) {charge_ = value;}
  void setpdgId(const int value) {pdgId_ = value;}
  void setstatus(const int value) {status_ = value;}
  void setLotentzVector(float pt, float eta, float phi, float e){SetPtEtaPhiE(pt, eta, phi, e);}
};

class Jet: public TLorentzVector{
friend class URStreamer;
public:
//  Jet(const int &i_charge_,const float &i_area_,const float &i_uncorrPt_,const float &i_uncorrEta_,const float &i_uncorrPhi_,const float &i_uncorrEnergy_,const float &i_chargedHadronEnergyFraction_,const float &i_neutralHadronEnergyFraction_,const float &i_chargedEmEnergyFraction_,const float &i_neutralEmEnergyFraction_,const float &i_HFHadronEnergyFraction_,const float &i_HFEMEnergyFraction_,const float &i_muonEnergyFraction_,const float &i_chargedMultiplicity_,const float &i_numChargedHadrons_,const float &i_numNeutralHadrons_,const float &i_numPhotons_,const float &i_numElectrons_,const float &i_numMuons_,const float &i_numForwardEMs_,const float &i_numForwardHads_,const float &i_numberOfDaughters_,const float &i_puId_,const float &i_csvIncl_,const float &i_CombinedMVA_,const float &i_CvsL_,const float &i_CvsB_,const float &i_DeepCSVlight_,const float &i_DeepCSVc_,const float &i_DeepCSVb_,const float &i_DeepCSVbb_,const int &i_partonFlavour_,const int &i_hadronFlavour_,const float &i_pupt_tight_,const float &i_pupt_loose_,const float &i_pupt_alltight_,const float &i_pupt_allloose_):
//    
//  {}
  Jet():
    TLorentzVector(),
    charge_(0),
    area_(0),
    uncorrPt_(0),
    uncorrEta_(0),
    uncorrPhi_(0),
    uncorrEnergy_(0),
    chargedHadronEnergyFraction_(0),
    neutralHadronEnergyFraction_(0),
    chargedEmEnergyFraction_(0),
    neutralEmEnergyFraction_(0),
    HFHadronEnergyFraction_(0),
    HFEMEnergyFraction_(0),
    muonEnergyFraction_(0),
    chargedMultiplicity_(0),
    numChargedHadrons_(0),
    numNeutralHadrons_(0),
    numPhotons_(0),
    numElectrons_(0),
    numMuons_(0),
    numForwardEMs_(0),
    numForwardHads_(0),
    numberOfDaughters_(0),
    puId_(0),
    csvIncl_(0),
    CombinedMVA_(0),
    CvsL_(0),
    CvsB_(0),
    DeepCSVlight_(0),
    DeepCSVc_(0),
    DeepCSVb_(0),
    DeepCSVbb_(0),
    partonFlavour_(0),
    hadronFlavour_(0),
    pupt_tight_(0),
    pupt_loose_(0),
    pupt_alltight_(0),
    pupt_allloose_(0)
  {}
  int charge() const {return charge_;}
  float area() const {return area_;}
  float uncorrPt() const {return uncorrPt_;}
  float uncorrEta() const {return uncorrEta_;}
  float uncorrPhi() const {return uncorrPhi_;}
  float uncorrEnergy() const {return uncorrEnergy_;}
  float chargedHadronEnergyFraction() const {return chargedHadronEnergyFraction_;}
  float neutralHadronEnergyFraction() const {return neutralHadronEnergyFraction_;}
  float chargedEmEnergyFraction() const {return chargedEmEnergyFraction_;}
  float neutralEmEnergyFraction() const {return neutralEmEnergyFraction_;}
  float HFHadronEnergyFraction() const {return HFHadronEnergyFraction_;}
  float HFEMEnergyFraction() const {return HFEMEnergyFraction_;}
  float muonEnergyFraction() const {return muonEnergyFraction_;}
  float chargedMultiplicity() const {return chargedMultiplicity_;}
  float numChargedHadrons() const {return numChargedHadrons_;}
  float numNeutralHadrons() const {return numNeutralHadrons_;}
  float numPhotons() const {return numPhotons_;}
  float numElectrons() const {return numElectrons_;}
  float numMuons() const {return numMuons_;}
  float numForwardEMs() const {return numForwardEMs_;}
  float numForwardHads() const {return numForwardHads_;}
  float numberOfDaughters() const {return numberOfDaughters_;}
  float puId() const {return puId_;}
  float csvIncl() const {return csvIncl_;}
  float CombinedMVA() const {return CombinedMVA_;}
  float CvsL() const {return CvsL_;}
  float CvsB() const {return CvsB_;}
  float DeepCSVlight() const {return DeepCSVlight_;}
  float DeepCSVc() const {return DeepCSVc_;}
  float DeepCSVb() const {return DeepCSVb_;}
  float DeepCSVbb() const {return DeepCSVbb_;}
  int partonFlavour() const {return partonFlavour_;}
  int hadronFlavour() const {return hadronFlavour_;}
  float pupt_tight() const {return pupt_tight_;}
  float pupt_loose() const {return pupt_loose_;}
  float pupt_alltight() const {return pupt_alltight_;}
  float pupt_allloose() const {return pupt_allloose_;}
  ClassDef(Jet, 1);
private:
  int charge_;
  float area_;
  float uncorrPt_;
  float uncorrEta_;
  float uncorrPhi_;
  float uncorrEnergy_;
  float chargedHadronEnergyFraction_;
  float neutralHadronEnergyFraction_;
  float chargedEmEnergyFraction_;
  float neutralEmEnergyFraction_;
  float HFHadronEnergyFraction_;
  float HFEMEnergyFraction_;
  float muonEnergyFraction_;
  float chargedMultiplicity_;
  float numChargedHadrons_;
  float numNeutralHadrons_;
  float numPhotons_;
  float numElectrons_;
  float numMuons_;
  float numForwardEMs_;
  float numForwardHads_;
  float numberOfDaughters_;
  float puId_;
  float csvIncl_;
  float CombinedMVA_;
  float CvsL_;
  float CvsB_;
  float DeepCSVlight_;
  float DeepCSVc_;
  float DeepCSVb_;
  float DeepCSVbb_;
  int partonFlavour_;
  int hadronFlavour_;
  float pupt_tight_;
  float pupt_loose_;
  float pupt_alltight_;
  float pupt_allloose_;
  void setcharge(const int value) {charge_ = value;}
  void setarea(const float value) {area_ = value;}
  void setuncorrPt(const float value) {uncorrPt_ = value;}
  void setuncorrEta(const float value) {uncorrEta_ = value;}
  void setuncorrPhi(const float value) {uncorrPhi_ = value;}
  void setuncorrEnergy(const float value) {uncorrEnergy_ = value;}
  void setchargedHadronEnergyFraction(const float value) {chargedHadronEnergyFraction_ = value;}
  void setneutralHadronEnergyFraction(const float value) {neutralHadronEnergyFraction_ = value;}
  void setchargedEmEnergyFraction(const float value) {chargedEmEnergyFraction_ = value;}
  void setneutralEmEnergyFraction(const float value) {neutralEmEnergyFraction_ = value;}
  void setHFHadronEnergyFraction(const float value) {HFHadronEnergyFraction_ = value;}
  void setHFEMEnergyFraction(const float value) {HFEMEnergyFraction_ = value;}
  void setmuonEnergyFraction(const float value) {muonEnergyFraction_ = value;}
  void setchargedMultiplicity(const float value) {chargedMultiplicity_ = value;}
  void setnumChargedHadrons(const float value) {numChargedHadrons_ = value;}
  void setnumNeutralHadrons(const float value) {numNeutralHadrons_ = value;}
  void setnumPhotons(const float value) {numPhotons_ = value;}
  void setnumElectrons(const float value) {numElectrons_ = value;}
  void setnumMuons(const float value) {numMuons_ = value;}
  void setnumForwardEMs(const float value) {numForwardEMs_ = value;}
  void setnumForwardHads(const float value) {numForwardHads_ = value;}
  void setnumberOfDaughters(const float value) {numberOfDaughters_ = value;}
  void setpuId(const float value) {puId_ = value;}
  void setcsvIncl(const float value) {csvIncl_ = value;}
  void setCombinedMVA(const float value) {CombinedMVA_ = value;}
  void setCvsL(const float value) {CvsL_ = value;}
  void setCvsB(const float value) {CvsB_ = value;}
  void setDeepCSVlight(const float value) {DeepCSVlight_ = value;}
  void setDeepCSVc(const float value) {DeepCSVc_ = value;}
  void setDeepCSVb(const float value) {DeepCSVb_ = value;}
  void setDeepCSVbb(const float value) {DeepCSVbb_ = value;}
  void setpartonFlavour(const int value) {partonFlavour_ = value;}
  void sethadronFlavour(const int value) {hadronFlavour_ = value;}
  void setpupt_tight(const float value) {pupt_tight_ = value;}
  void setpupt_loose(const float value) {pupt_loose_ = value;}
  void setpupt_alltight(const float value) {pupt_alltight_ = value;}
  void setpupt_allloose(const float value) {pupt_allloose_ = value;}
  void setLotentzVector(float pt, float eta, float phi, float e){SetPtEtaPhiE(pt, eta, phi, e);}
};

class Muon: public TLorentzVector{
friend class URStreamer;
public:
//  Muon(const int &i_charge_,const float &i_dB_,const float &i_ipDXY_,const float &i_dz_,const float &i_nMissingInnerHits_,const float &i_ECalEnergy_,const float &i_HCalEnergy_,const int &i_numMatchedStations_,const float &i_pfChargedIso04_,const float &i_pfNeutralIso04_,const float &i_pfPhotonIso04_,const float &i_pfPUIso04_,const float &i_trkIso03_,const float &i_ptErr_,const float &i_chi2_,const int &i_ndof_,const float &i_validHits_,const float &i_pixelHits_,const float &i_trackerLayers_,const bool &i_isGlobal_,const bool &i_isTracker_,const bool &i_isCalo_,const bool &i_isPF_,const bool &i_isStandAlone_,const bool &i_HLT_IsoTkMu24_,const bool &i_HLT_IsoMu24_,const bool &i_HLT_IsoTkMu27_,const bool &i_HLT_IsoMu27_):
//    
//  {}
  Muon():
    TLorentzVector(),
    charge_(0),
    dB_(0),
    ipDXY_(0),
    dz_(0),
    nMissingInnerHits_(0),
    ECalEnergy_(0),
    HCalEnergy_(0),
    numMatchedStations_(0),
    pfChargedIso04_(0),
    pfNeutralIso04_(0),
    pfPhotonIso04_(0),
    pfPUIso04_(0),
    trkIso03_(0),
    ptErr_(0),
    chi2_(0),
    ndof_(0),
    validHits_(0),
    pixelHits_(0),
    trackerLayers_(0),
    isGlobal_(0),
    isTracker_(0),
    isCalo_(0),
    isPF_(0),
    isStandAlone_(0),
    HLT_IsoTkMu24_(0),
    HLT_IsoMu24_(0),
    HLT_IsoTkMu27_(0),
    HLT_IsoMu27_(0)
  {}
  int charge() const {return charge_;}
  float dB() const {return dB_;}
  float ipDXY() const {return ipDXY_;}
  float dz() const {return dz_;}
  float nMissingInnerHits() const {return nMissingInnerHits_;}
  float ECalEnergy() const {return ECalEnergy_;}
  float HCalEnergy() const {return HCalEnergy_;}
  int numMatchedStations() const {return numMatchedStations_;}
  float pfChargedIso04() const {return pfChargedIso04_;}
  float pfNeutralIso04() const {return pfNeutralIso04_;}
  float pfPhotonIso04() const {return pfPhotonIso04_;}
  float pfPUIso04() const {return pfPUIso04_;}
  float trkIso03() const {return trkIso03_;}
  float ptErr() const {return ptErr_;}
  float chi2() const {return chi2_;}
  int ndof() const {return ndof_;}
  float validHits() const {return validHits_;}
  float pixelHits() const {return pixelHits_;}
  float trackerLayers() const {return trackerLayers_;}
  bool isGlobal() const {return isGlobal_;}
  bool isTracker() const {return isTracker_;}
  bool isCalo() const {return isCalo_;}
  bool isPF() const {return isPF_;}
  bool isStandAlone() const {return isStandAlone_;}
  bool HLT_IsoTkMu24() const {return HLT_IsoTkMu24_;}
  bool HLT_IsoMu24() const {return HLT_IsoMu24_;}
  bool HLT_IsoTkMu27() const {return HLT_IsoTkMu27_;}
  bool HLT_IsoMu27() const {return HLT_IsoMu27_;}
  ClassDef(Muon, 1);
private:
  int charge_;
  float dB_;
  float ipDXY_;
  float dz_;
  float nMissingInnerHits_;
  float ECalEnergy_;
  float HCalEnergy_;
  int numMatchedStations_;
  float pfChargedIso04_;
  float pfNeutralIso04_;
  float pfPhotonIso04_;
  float pfPUIso04_;
  float trkIso03_;
  float ptErr_;
  float chi2_;
  int ndof_;
  float validHits_;
  float pixelHits_;
  float trackerLayers_;
  bool isGlobal_;
  bool isTracker_;
  bool isCalo_;
  bool isPF_;
  bool isStandAlone_;
  bool HLT_IsoTkMu24_;
  bool HLT_IsoMu24_;
  bool HLT_IsoTkMu27_;
  bool HLT_IsoMu27_;
  void setcharge(const int value) {charge_ = value;}
  void setdB(const float value) {dB_ = value;}
  void setipDXY(const float value) {ipDXY_ = value;}
  void setdz(const float value) {dz_ = value;}
  void setnMissingInnerHits(const float value) {nMissingInnerHits_ = value;}
  void setECalEnergy(const float value) {ECalEnergy_ = value;}
  void setHCalEnergy(const float value) {HCalEnergy_ = value;}
  void setnumMatchedStations(const int value) {numMatchedStations_ = value;}
  void setpfChargedIso04(const float value) {pfChargedIso04_ = value;}
  void setpfNeutralIso04(const float value) {pfNeutralIso04_ = value;}
  void setpfPhotonIso04(const float value) {pfPhotonIso04_ = value;}
  void setpfPUIso04(const float value) {pfPUIso04_ = value;}
  void settrkIso03(const float value) {trkIso03_ = value;}
  void setptErr(const float value) {ptErr_ = value;}
  void setchi2(const float value) {chi2_ = value;}
  void setndof(const int value) {ndof_ = value;}
  void setvalidHits(const float value) {validHits_ = value;}
  void setpixelHits(const float value) {pixelHits_ = value;}
  void settrackerLayers(const float value) {trackerLayers_ = value;}
  void setisGlobal(const bool value) {isGlobal_ = value;}
  void setisTracker(const bool value) {isTracker_ = value;}
  void setisCalo(const bool value) {isCalo_ = value;}
  void setisPF(const bool value) {isPF_ = value;}
  void setisStandAlone(const bool value) {isStandAlone_ = value;}
  void setHLT_IsoTkMu24(const bool value) {HLT_IsoTkMu24_ = value;}
  void setHLT_IsoMu24(const bool value) {HLT_IsoMu24_ = value;}
  void setHLT_IsoTkMu27(const bool value) {HLT_IsoTkMu27_ = value;}
  void setHLT_IsoMu27(const bool value) {HLT_IsoMu27_ = value;}
  void setLotentzVector(float pt, float eta, float phi, float e){SetPtEtaPhiE(pt, eta, phi, e);}
};

class Lhe: public TLorentzVector{
friend class URStreamer;
public:
//  Lhe(const int &i_pdgid_,const int &i_status_,const int &i_fmother_,const int &i_lmother_):
//    
//  {}
  Lhe():
    TLorentzVector(),
    pdgid_(0),
    status_(0),
    fmother_(0),
    lmother_(0)
  {}
  int pdgid() const {return pdgid_;}
  int status() const {return status_;}
  int fmother() const {return fmother_;}
  int lmother() const {return lmother_;}
  ClassDef(Lhe, 1);
private:
  int pdgid_;
  int status_;
  int fmother_;
  int lmother_;
  void setpdgid(const int value) {pdgid_ = value;}
  void setstatus(const int value) {status_ = value;}
  void setfmother(const int value) {fmother_ = value;}
  void setlmother(const int value) {lmother_ = value;}
  void setLotentzVector(float px, float py, float pz, float e){SetPxPyPzE(px, py, pz, e);}
};

class Vertex{
friend class URStreamer;
public:
//  Vertex(const float &i_x_,const float &i_y_,const float &i_z_,const float &i_chi2_,const float &i_ndof_,const float &i_nTracks_):
//    
//  {}
  Vertex():
    x_(0),
    y_(0),
    z_(0),
    chi2_(0),
    ndof_(0),
    nTracks_(0)
  {}
  float x() const {return x_;}
  float y() const {return y_;}
  float z() const {return z_;}
  float chi2() const {return chi2_;}
  float ndof() const {return ndof_;}
  float nTracks() const {return nTracks_;}
private:
  float x_;
  float y_;
  float z_;
  float chi2_;
  float ndof_;
  float nTracks_;
  void setx(const float value) {x_ = value;}
  void sety(const float value) {y_ = value;}
  void setz(const float value) {z_ = value;}
  void setchi2(const float value) {chi2_ = value;}
  void setndof(const float value) {ndof_ = value;}
  void setnTracks(const float value) {nTracks_ = value;}
};

class Puinfo{
friend class URStreamer;
public:
//  Puinfo(const float &i_bx_,const float &i_nPU_,const float &i_nInteractions_):
//    
//  {}
  Puinfo():
    bx_(0),
    nPU_(0),
    nInteractions_(0)
  {}
  float bx() const {return bx_;}
  float nPU() const {return nPU_;}
  float nInteractions() const {return nInteractions_;}
private:
  float bx_;
  float nPU_;
  float nInteractions_;
  void setbx(const float value) {bx_ = value;}
  void setnPU(const float value) {nPU_ = value;}
  void setnInteractions(const float value) {nInteractions_ = value;}
};


class URStreamer{
public:
  UInt_t run;
  UInt_t lumi;
  UInt_t evt;

  URStreamer(TTree *tree):
    run(0),
    lumi(0),
    evt(0),
    trigger_HLT_notexists_(0),
    trigger_HLT_IsoTkMu24_(0),
    trigger_HLT_IsoMu24_(0),
    trigger_HLT_IsoTkMu27_(0),
    trigger_HLT_IsoMu27_(0),
    trigger_HLT_Ele27_eta2p1_WPTight_Gsf_(0),
    trigger_HLT_Ele32_eta2p1_WPTight_Gsf_(0),
    trigger_HLT_Ele32_WPTight_Gsf_(0),
    trigger_HLT_Ele27_WPTight_Gsf_(0),
    trigger_L1_SingleIsoEG34er_(0),
    trigger_L1_SingleIsoEG34_(0),
    trigger_L1_SingleIsoEG32er_(0),
    trigger_L1_SingleIsoEG32_(0),
    trigger_PSColumn_(0),
    trigger_El27ptmax_(0),
    filter_Flag_goodVertices_(0),
    filter_Flag_CSCTightHaloFilter_(0),
    filter_Flag_trkPOGFilters_(0),
    filter_Flag_trkPOG_logErrorTooManyClusters_(0),
    filter_Flag_EcalDeadCellTriggerPrimitiveFilter_(0),
    filter_Flag_ecalLaserCorrFilter_(0),
    filter_Flag_trkPOG_manystripclus53X_(0),
    filter_Flag_eeBadScFilter_(0),
    filter_Flag_METFilters_(0),
    filter_Flag_HBHENoiseFilter_(0),
    filter_Flag_trkPOG_toomanystripclus53X_(0),
    filter_Flag_hcalLaserEventFilter_(0),
    rho_value_(0),
    muons_e_(0),
    muons_pt_(0),
    muons_eta_(0),
    muons_phi_(0),
    muons_charge_(0),
    muons_dB_(0),
    muons_ipDXY_(0),
    muons_dz_(0),
    muons_nMissingInnerHits_(0),
    muons_ECalEnergy_(0),
    muons_HCalEnergy_(0),
    muons_numMatchedStations_(0),
    muons_pfChargedIso04_(0),
    muons_pfNeutralIso04_(0),
    muons_pfPhotonIso04_(0),
    muons_pfPUIso04_(0),
    muons_trkIso03_(0),
    muons_ptErr_(0),
    muons_chi2_(0),
    muons_ndof_(0),
    muons_validHits_(0),
    muons_pixelHits_(0),
    muons_trackerLayers_(0),
    muons_isGlobal_(0),
    muons_isTracker_(0),
    muons_isCalo_(0),
    muons_isPF_(0),
    muons_isStandAlone_(0),
    muons_HLT_IsoTkMu24_(0),
    muons_HLT_IsoMu24_(0),
    muons_HLT_IsoTkMu27_(0),
    muons_HLT_IsoMu27_(0),
    jets_e_(0),
    jets_pt_(0),
    jets_eta_(0),
    jets_phi_(0),
    jets_charge_(0),
    jets_area_(0),
    jets_uncorrPt_(0),
    jets_uncorrEta_(0),
    jets_uncorrPhi_(0),
    jets_uncorrEnergy_(0),
    jets_chargedHadronEnergyFraction_(0),
    jets_neutralHadronEnergyFraction_(0),
    jets_chargedEmEnergyFraction_(0),
    jets_neutralEmEnergyFraction_(0),
    jets_HFHadronEnergyFraction_(0),
    jets_HFEMEnergyFraction_(0),
    jets_muonEnergyFraction_(0),
    jets_chargedMultiplicity_(0),
    jets_numChargedHadrons_(0),
    jets_numNeutralHadrons_(0),
    jets_numPhotons_(0),
    jets_numElectrons_(0),
    jets_numMuons_(0),
    jets_numForwardEMs_(0),
    jets_numForwardHads_(0),
    jets_numberOfDaughters_(0),
    jets_puId_(0),
    jets_csvIncl_(0),
    jets_CombinedMVA_(0),
    jets_CvsL_(0),
    jets_CvsB_(0),
    jets_DeepCSVlight_(0),
    jets_DeepCSVc_(0),
    jets_DeepCSVb_(0),
    jets_DeepCSVbb_(0),
    jets_partonFlavour_(0),
    jets_hadronFlavour_(0),
    jets_pupt_tight_(0),
    jets_pupt_loose_(0),
    jets_pupt_alltight_(0),
    jets_pupt_allloose_(0),
    electrons_e_(0),
    electrons_pt_(0),
    electrons_eta_(0),
    electrons_phi_(0),
    electrons_charge_(0),
    electrons_dB_(0),
    electrons_ipDXY_(0),
    electrons_dz_(0),
    electrons_nMissingInnerHits_(0),
    electrons_SCeta_(0),
    electrons_DEtaSCTrk_(0),
    electrons_DPhiSCTrk_(0),
    electrons_ESCOverETrack_(0),
    electrons_ecalEnergy_(0),
    electrons_full5x5_sigmaIEtaIEta_(0),
    electrons_hadronicOverEM_(0),
    electrons_isEB_(0),
    electrons_isEE_(0),
    electrons_pfChargedIso_(0),
    electrons_pfNeutralIso_(0),
    electrons_pfPhotonIso_(0),
    electrons_pfPUIso_(0),
    electrons_HLT_Ele27_eta2p1_WPTight_Gsf_(0),
    electrons_HLT_Ele32_eta2p1_WPTight_Gsf_(0),
    electrons_HLT_Ele32_WPTight_Gsf_(0),
    electrons_HLT_Ele27_WPTight_Gsf_(0),
    electrons_conversion_(0),
    photons_e_(0),
    photons_pt_(0),
    photons_eta_(0),
    photons_phi_(0),
    photons_charge_(0),
    photons_x_(0),
    photons_y_(0),
    photons_z_(0),
    photons_energy_(0),
    photons_rawEnergy_(0),
    photons_phiWidth_(0),
    photons_etaWidth_(0),
    photons_e3x3_(0),
    photons_maxCrystalEnergy_(0),
    photons_isEB_(0),
    photons_isEE_(0),
    photons_isPFlowPhoton_(0),
    photons_hasConversionTracks_(0),
    photons_hasPixelSeed_(0),
    vertexs_x_(0),
    vertexs_y_(0),
    vertexs_z_(0),
    vertexs_chi2_(0),
    vertexs_ndof_(0),
    vertexs_nTracks_(0),
    METs_px_(0),
    METs_py_(0),
    METs_pxunc_(0),
    METs_pyunc_(0),
    genInfo_weight_(0),
    genInfo_pdfid1_(0),
    genInfo_pdfid2_(0),
    genInfo_x1_(0),
    genInfo_x2_(0),
    genInfo_renScale_(0),
    MCWeights_weights_(0),
    lhes_px_(0),
    lhes_py_(0),
    lhes_pz_(0),
    lhes_e_(0),
    lhes_pdgid_(0),
    lhes_status_(0),
    lhes_fmother_(0),
    lhes_lmother_(0),
    PUInfos_bx_(0),
    PUInfos_nPU_(0),
    PUInfos_nInteractions_(0),
    PLs_e_(0),
    PLs_pt_(0),
    PLs_eta_(0),
    PLs_phi_(0),
    PLs_charge_(0),
    PLs_pdgId_(0),
    PLs_status_(0),
    PLs_isoR3_(0),
    PLs_isoR4_(0),
    RivetPLs_e_(0),
    RivetPLs_pt_(0),
    RivetPLs_eta_(0),
    RivetPLs_phi_(0),
    RivetPLs_charge_(0),
    RivetPLs_pdgId_(0),
    RivetPLs_status_(0),
    TTGens_e_(0),
    TTGens_pt_(0),
    TTGens_eta_(0),
    TTGens_phi_(0),
    TTGens_charge_(0),
    TTGens_pdgId_(0),
    TTGens_status_(0),
    are_METs_loaded_(0), METs_(),
    are_PLs_loaded_(0), PLs_(),
    are_MCWeights_loaded_(0), MCWeights_(),
    are_genInfo_loaded_(0), genInfo_(),
    are_photons_loaded_(0), photons_(),
    are_TTGens_loaded_(0), TTGens_(),
    are_filter_loaded_(0), filter_(),
    are_trigger_loaded_(0), trigger_(),
    are_electrons_loaded_(0), electrons_(),
    are_rho_loaded_(0), rho_(),
    are_RivetPLs_loaded_(0), RivetPLs_(),
    are_jets_loaded_(0), jets_(),
    are_muons_loaded_(0), muons_(),
    are_lhes_loaded_(0), lhes_(),
    are_vertexs_loaded_(0), vertexs_(),
    are_PUInfos_loaded_(0), PUInfos_()
  {
    tree_ = tree;
    current_entry_ = -1;
    entries_ = tree_->GetEntries();
    tree_->SetBranchStatus("*",0); 
    tree_->SetBranchStatus("run", 1); tree_->SetBranchAddress("run", &run);
    tree_->SetBranchStatus("lumi", 1); tree_->SetBranchAddress("lumi", &lumi);
    tree_->SetBranchStatus("evt", 1); tree_->SetBranchAddress("evt", &evt);
  }

  ~URStreamer()
  {
    //{ EVT_DESTROY }
  }

  bool next(){
    METs_.clear();
    PLs_.clear();
    MCWeights_.clear();
    
    photons_.clear();
    TTGens_.clear();
    
    
    electrons_.clear();
    
    RivetPLs_.clear();
    jets_.clear();
    muons_.clear();
    lhes_.clear();
    vertexs_.clear();
    PUInfos_.clear();
    current_entry_++;
    if(current_entry_ < entries_){
      tree_->GetEntry(current_entry_);
      return true;
    }
    return false;
  }

  void loadMets(){
    if(!are_METs_loaded_){
      tree_->SetBranchStatus("METs.px", 1); tree_->SetBranchAddress("METs.px", &METs_px_);
      tree_->SetBranchStatus("METs.py", 1); tree_->SetBranchAddress("METs.py", &METs_py_);
      tree_->SetBranchStatus("METs.pxunc", 1); tree_->SetBranchAddress("METs.pxunc", &METs_pxunc_);
      tree_->SetBranchStatus("METs.pyunc", 1); tree_->SetBranchAddress("METs.pyunc", &METs_pyunc_);
      are_METs_loaded_ = true;
      tree_->GetEntry(current_entry_);
    }
  }
  
  void loadPls(){
    if(!are_PLs_loaded_){
      tree_->SetBranchStatus("PLs.e", 1); tree_->SetBranchAddress("PLs.e", &PLs_e_);
      tree_->SetBranchStatus("PLs.pt", 1); tree_->SetBranchAddress("PLs.pt", &PLs_pt_);
      tree_->SetBranchStatus("PLs.eta", 1); tree_->SetBranchAddress("PLs.eta", &PLs_eta_);
      tree_->SetBranchStatus("PLs.phi", 1); tree_->SetBranchAddress("PLs.phi", &PLs_phi_);
      tree_->SetBranchStatus("PLs.charge", 1); tree_->SetBranchAddress("PLs.charge", &PLs_charge_);
      tree_->SetBranchStatus("PLs.pdgId", 1); tree_->SetBranchAddress("PLs.pdgId", &PLs_pdgId_);
      tree_->SetBranchStatus("PLs.status", 1); tree_->SetBranchAddress("PLs.status", &PLs_status_);
      tree_->SetBranchStatus("PLs.isoR3", 1); tree_->SetBranchAddress("PLs.isoR3", &PLs_isoR3_);
      tree_->SetBranchStatus("PLs.isoR4", 1); tree_->SetBranchAddress("PLs.isoR4", &PLs_isoR4_);
      are_PLs_loaded_ = true;
      tree_->GetEntry(current_entry_);
    }
  }
  
  void loadMcweights(){
    if(!are_MCWeights_loaded_){
      tree_->SetBranchStatus("MCWeights.weights", 1); tree_->SetBranchAddress("MCWeights.weights", &MCWeights_weights_);
      are_MCWeights_loaded_ = true;
      tree_->GetEntry(current_entry_);
    }
  }
  
  void loadGeninfo(){
    if(!are_genInfo_loaded_){
      tree_->SetBranchStatus("genInfo.weight", 1); tree_->SetBranchAddress("genInfo.weight", &genInfo_weight_);
      tree_->SetBranchStatus("genInfo.pdfid1", 1); tree_->SetBranchAddress("genInfo.pdfid1", &genInfo_pdfid1_);
      tree_->SetBranchStatus("genInfo.pdfid2", 1); tree_->SetBranchAddress("genInfo.pdfid2", &genInfo_pdfid2_);
      tree_->SetBranchStatus("genInfo.x1", 1); tree_->SetBranchAddress("genInfo.x1", &genInfo_x1_);
      tree_->SetBranchStatus("genInfo.x2", 1); tree_->SetBranchAddress("genInfo.x2", &genInfo_x2_);
      tree_->SetBranchStatus("genInfo.renScale", 1); tree_->SetBranchAddress("genInfo.renScale", &genInfo_renScale_);
      are_genInfo_loaded_ = true;
      tree_->GetEntry(current_entry_);
    }
  }
  
  void loadPhotons(){
    if(!are_photons_loaded_){
      tree_->SetBranchStatus("photons.e", 1); tree_->SetBranchAddress("photons.e", &photons_e_);
      tree_->SetBranchStatus("photons.pt", 1); tree_->SetBranchAddress("photons.pt", &photons_pt_);
      tree_->SetBranchStatus("photons.eta", 1); tree_->SetBranchAddress("photons.eta", &photons_eta_);
      tree_->SetBranchStatus("photons.phi", 1); tree_->SetBranchAddress("photons.phi", &photons_phi_);
      tree_->SetBranchStatus("photons.charge", 1); tree_->SetBranchAddress("photons.charge", &photons_charge_);
      tree_->SetBranchStatus("photons.x", 1); tree_->SetBranchAddress("photons.x", &photons_x_);
      tree_->SetBranchStatus("photons.y", 1); tree_->SetBranchAddress("photons.y", &photons_y_);
      tree_->SetBranchStatus("photons.z", 1); tree_->SetBranchAddress("photons.z", &photons_z_);
      tree_->SetBranchStatus("photons.energy", 1); tree_->SetBranchAddress("photons.energy", &photons_energy_);
      tree_->SetBranchStatus("photons.rawEnergy", 1); tree_->SetBranchAddress("photons.rawEnergy", &photons_rawEnergy_);
      tree_->SetBranchStatus("photons.phiWidth", 1); tree_->SetBranchAddress("photons.phiWidth", &photons_phiWidth_);
      tree_->SetBranchStatus("photons.etaWidth", 1); tree_->SetBranchAddress("photons.etaWidth", &photons_etaWidth_);
      tree_->SetBranchStatus("photons.e3x3", 1); tree_->SetBranchAddress("photons.e3x3", &photons_e3x3_);
      tree_->SetBranchStatus("photons.maxCrystalEnergy", 1); tree_->SetBranchAddress("photons.maxCrystalEnergy", &photons_maxCrystalEnergy_);
      tree_->SetBranchStatus("photons.isEB", 1); tree_->SetBranchAddress("photons.isEB", &photons_isEB_);
      tree_->SetBranchStatus("photons.isEE", 1); tree_->SetBranchAddress("photons.isEE", &photons_isEE_);
      tree_->SetBranchStatus("photons.isPFlowPhoton", 1); tree_->SetBranchAddress("photons.isPFlowPhoton", &photons_isPFlowPhoton_);
      tree_->SetBranchStatus("photons.hasConversionTracks", 1); tree_->SetBranchAddress("photons.hasConversionTracks", &photons_hasConversionTracks_);
      tree_->SetBranchStatus("photons.hasPixelSeed", 1); tree_->SetBranchAddress("photons.hasPixelSeed", &photons_hasPixelSeed_);
      are_photons_loaded_ = true;
      tree_->GetEntry(current_entry_);
    }
  }
  
  void loadTtgens(){
    if(!are_TTGens_loaded_){
      tree_->SetBranchStatus("TTGens.e", 1); tree_->SetBranchAddress("TTGens.e", &TTGens_e_);
      tree_->SetBranchStatus("TTGens.pt", 1); tree_->SetBranchAddress("TTGens.pt", &TTGens_pt_);
      tree_->SetBranchStatus("TTGens.eta", 1); tree_->SetBranchAddress("TTGens.eta", &TTGens_eta_);
      tree_->SetBranchStatus("TTGens.phi", 1); tree_->SetBranchAddress("TTGens.phi", &TTGens_phi_);
      tree_->SetBranchStatus("TTGens.charge", 1); tree_->SetBranchAddress("TTGens.charge", &TTGens_charge_);
      tree_->SetBranchStatus("TTGens.pdgId", 1); tree_->SetBranchAddress("TTGens.pdgId", &TTGens_pdgId_);
      tree_->SetBranchStatus("TTGens.status", 1); tree_->SetBranchAddress("TTGens.status", &TTGens_status_);
      are_TTGens_loaded_ = true;
      tree_->GetEntry(current_entry_);
    }
  }
  
  void loadFilter(){
    if(!are_filter_loaded_){
      tree_->SetBranchStatus("filter.Flag_goodVertices", 1); tree_->SetBranchAddress("filter.Flag_goodVertices", &filter_Flag_goodVertices_);
      tree_->SetBranchStatus("filter.Flag_CSCTightHaloFilter", 1); tree_->SetBranchAddress("filter.Flag_CSCTightHaloFilter", &filter_Flag_CSCTightHaloFilter_);
      tree_->SetBranchStatus("filter.Flag_trkPOGFilters", 1); tree_->SetBranchAddress("filter.Flag_trkPOGFilters", &filter_Flag_trkPOGFilters_);
      tree_->SetBranchStatus("filter.Flag_trkPOG_logErrorTooManyClusters", 1); tree_->SetBranchAddress("filter.Flag_trkPOG_logErrorTooManyClusters", &filter_Flag_trkPOG_logErrorTooManyClusters_);
      tree_->SetBranchStatus("filter.Flag_EcalDeadCellTriggerPrimitiveFilter", 1); tree_->SetBranchAddress("filter.Flag_EcalDeadCellTriggerPrimitiveFilter", &filter_Flag_EcalDeadCellTriggerPrimitiveFilter_);
      tree_->SetBranchStatus("filter.Flag_ecalLaserCorrFilter", 1); tree_->SetBranchAddress("filter.Flag_ecalLaserCorrFilter", &filter_Flag_ecalLaserCorrFilter_);
      tree_->SetBranchStatus("filter.Flag_trkPOG_manystripclus53X", 1); tree_->SetBranchAddress("filter.Flag_trkPOG_manystripclus53X", &filter_Flag_trkPOG_manystripclus53X_);
      tree_->SetBranchStatus("filter.Flag_eeBadScFilter", 1); tree_->SetBranchAddress("filter.Flag_eeBadScFilter", &filter_Flag_eeBadScFilter_);
      tree_->SetBranchStatus("filter.Flag_METFilters", 1); tree_->SetBranchAddress("filter.Flag_METFilters", &filter_Flag_METFilters_);
      tree_->SetBranchStatus("filter.Flag_HBHENoiseFilter", 1); tree_->SetBranchAddress("filter.Flag_HBHENoiseFilter", &filter_Flag_HBHENoiseFilter_);
      tree_->SetBranchStatus("filter.Flag_trkPOG_toomanystripclus53X", 1); tree_->SetBranchAddress("filter.Flag_trkPOG_toomanystripclus53X", &filter_Flag_trkPOG_toomanystripclus53X_);
      tree_->SetBranchStatus("filter.Flag_hcalLaserEventFilter", 1); tree_->SetBranchAddress("filter.Flag_hcalLaserEventFilter", &filter_Flag_hcalLaserEventFilter_);
      are_filter_loaded_ = true;
      tree_->GetEntry(current_entry_);
    }
  }
  
  void loadTrigger(){
    if(!are_trigger_loaded_){
      tree_->SetBranchStatus("trigger.HLT_notexists", 1); tree_->SetBranchAddress("trigger.HLT_notexists", &trigger_HLT_notexists_);
      tree_->SetBranchStatus("trigger.HLT_IsoTkMu24", 1); tree_->SetBranchAddress("trigger.HLT_IsoTkMu24", &trigger_HLT_IsoTkMu24_);
      tree_->SetBranchStatus("trigger.HLT_IsoMu24", 1); tree_->SetBranchAddress("trigger.HLT_IsoMu24", &trigger_HLT_IsoMu24_);
      tree_->SetBranchStatus("trigger.HLT_IsoTkMu27", 1); tree_->SetBranchAddress("trigger.HLT_IsoTkMu27", &trigger_HLT_IsoTkMu27_);
      tree_->SetBranchStatus("trigger.HLT_IsoMu27", 1); tree_->SetBranchAddress("trigger.HLT_IsoMu27", &trigger_HLT_IsoMu27_);
      tree_->SetBranchStatus("trigger.HLT_Ele27_eta2p1_WPTight_Gsf", 1); tree_->SetBranchAddress("trigger.HLT_Ele27_eta2p1_WPTight_Gsf", &trigger_HLT_Ele27_eta2p1_WPTight_Gsf_);
      tree_->SetBranchStatus("trigger.HLT_Ele32_eta2p1_WPTight_Gsf", 1); tree_->SetBranchAddress("trigger.HLT_Ele32_eta2p1_WPTight_Gsf", &trigger_HLT_Ele32_eta2p1_WPTight_Gsf_);
      tree_->SetBranchStatus("trigger.HLT_Ele32_WPTight_Gsf", 1); tree_->SetBranchAddress("trigger.HLT_Ele32_WPTight_Gsf", &trigger_HLT_Ele32_WPTight_Gsf_);
      tree_->SetBranchStatus("trigger.HLT_Ele27_WPTight_Gsf", 1); tree_->SetBranchAddress("trigger.HLT_Ele27_WPTight_Gsf", &trigger_HLT_Ele27_WPTight_Gsf_);
      tree_->SetBranchStatus("trigger.L1_SingleIsoEG34er", 1); tree_->SetBranchAddress("trigger.L1_SingleIsoEG34er", &trigger_L1_SingleIsoEG34er_);
      tree_->SetBranchStatus("trigger.L1_SingleIsoEG34", 1); tree_->SetBranchAddress("trigger.L1_SingleIsoEG34", &trigger_L1_SingleIsoEG34_);
      tree_->SetBranchStatus("trigger.L1_SingleIsoEG32er", 1); tree_->SetBranchAddress("trigger.L1_SingleIsoEG32er", &trigger_L1_SingleIsoEG32er_);
      tree_->SetBranchStatus("trigger.L1_SingleIsoEG32", 1); tree_->SetBranchAddress("trigger.L1_SingleIsoEG32", &trigger_L1_SingleIsoEG32_);
      tree_->SetBranchStatus("trigger.PSColumn", 1); tree_->SetBranchAddress("trigger.PSColumn", &trigger_PSColumn_);
      tree_->SetBranchStatus("trigger.El27ptmax", 1); tree_->SetBranchAddress("trigger.El27ptmax", &trigger_El27ptmax_);
      are_trigger_loaded_ = true;
      tree_->GetEntry(current_entry_);
    }
  }
  
  void loadElectrons(){
    if(!are_electrons_loaded_){
      tree_->SetBranchStatus("electrons.e", 1); tree_->SetBranchAddress("electrons.e", &electrons_e_);
      tree_->SetBranchStatus("electrons.pt", 1); tree_->SetBranchAddress("electrons.pt", &electrons_pt_);
      tree_->SetBranchStatus("electrons.eta", 1); tree_->SetBranchAddress("electrons.eta", &electrons_eta_);
      tree_->SetBranchStatus("electrons.phi", 1); tree_->SetBranchAddress("electrons.phi", &electrons_phi_);
      tree_->SetBranchStatus("electrons.charge", 1); tree_->SetBranchAddress("electrons.charge", &electrons_charge_);
      tree_->SetBranchStatus("electrons.dB", 1); tree_->SetBranchAddress("electrons.dB", &electrons_dB_);
      tree_->SetBranchStatus("electrons.ipDXY", 1); tree_->SetBranchAddress("electrons.ipDXY", &electrons_ipDXY_);
      tree_->SetBranchStatus("electrons.dz", 1); tree_->SetBranchAddress("electrons.dz", &electrons_dz_);
      tree_->SetBranchStatus("electrons.nMissingInnerHits", 1); tree_->SetBranchAddress("electrons.nMissingInnerHits", &electrons_nMissingInnerHits_);
      tree_->SetBranchStatus("electrons.SCeta", 1); tree_->SetBranchAddress("electrons.SCeta", &electrons_SCeta_);
      tree_->SetBranchStatus("electrons.DEtaSCTrk", 1); tree_->SetBranchAddress("electrons.DEtaSCTrk", &electrons_DEtaSCTrk_);
      tree_->SetBranchStatus("electrons.DPhiSCTrk", 1); tree_->SetBranchAddress("electrons.DPhiSCTrk", &electrons_DPhiSCTrk_);
      tree_->SetBranchStatus("electrons.ESCOverETrack", 1); tree_->SetBranchAddress("electrons.ESCOverETrack", &electrons_ESCOverETrack_);
      tree_->SetBranchStatus("electrons.ecalEnergy", 1); tree_->SetBranchAddress("electrons.ecalEnergy", &electrons_ecalEnergy_);
      tree_->SetBranchStatus("electrons.full5x5_sigmaIEtaIEta", 1); tree_->SetBranchAddress("electrons.full5x5_sigmaIEtaIEta", &electrons_full5x5_sigmaIEtaIEta_);
      tree_->SetBranchStatus("electrons.hadronicOverEM", 1); tree_->SetBranchAddress("electrons.hadronicOverEM", &electrons_hadronicOverEM_);
      tree_->SetBranchStatus("electrons.isEB", 1); tree_->SetBranchAddress("electrons.isEB", &electrons_isEB_);
      tree_->SetBranchStatus("electrons.isEE", 1); tree_->SetBranchAddress("electrons.isEE", &electrons_isEE_);
      tree_->SetBranchStatus("electrons.pfChargedIso", 1); tree_->SetBranchAddress("electrons.pfChargedIso", &electrons_pfChargedIso_);
      tree_->SetBranchStatus("electrons.pfNeutralIso", 1); tree_->SetBranchAddress("electrons.pfNeutralIso", &electrons_pfNeutralIso_);
      tree_->SetBranchStatus("electrons.pfPhotonIso", 1); tree_->SetBranchAddress("electrons.pfPhotonIso", &electrons_pfPhotonIso_);
      tree_->SetBranchStatus("electrons.pfPUIso", 1); tree_->SetBranchAddress("electrons.pfPUIso", &electrons_pfPUIso_);
      tree_->SetBranchStatus("electrons.HLT_Ele27_eta2p1_WPTight_Gsf", 1); tree_->SetBranchAddress("electrons.HLT_Ele27_eta2p1_WPTight_Gsf", &electrons_HLT_Ele27_eta2p1_WPTight_Gsf_);
      tree_->SetBranchStatus("electrons.HLT_Ele32_eta2p1_WPTight_Gsf", 1); tree_->SetBranchAddress("electrons.HLT_Ele32_eta2p1_WPTight_Gsf", &electrons_HLT_Ele32_eta2p1_WPTight_Gsf_);
      tree_->SetBranchStatus("electrons.HLT_Ele32_WPTight_Gsf", 1); tree_->SetBranchAddress("electrons.HLT_Ele32_WPTight_Gsf", &electrons_HLT_Ele32_WPTight_Gsf_);
      tree_->SetBranchStatus("electrons.HLT_Ele27_WPTight_Gsf", 1); tree_->SetBranchAddress("electrons.HLT_Ele27_WPTight_Gsf", &electrons_HLT_Ele27_WPTight_Gsf_);
      tree_->SetBranchStatus("electrons.conversion", 1); tree_->SetBranchAddress("electrons.conversion", &electrons_conversion_);
      are_electrons_loaded_ = true;
      tree_->GetEntry(current_entry_);
    }
  }
  
  void loadRho(){
    if(!are_rho_loaded_){
      tree_->SetBranchStatus("rho.value", 1); tree_->SetBranchAddress("rho.value", &rho_value_);
      are_rho_loaded_ = true;
      tree_->GetEntry(current_entry_);
    }
  }
  
  void loadRivetpls(){
    if(!are_RivetPLs_loaded_){
      tree_->SetBranchStatus("RivetPLs.e", 1); tree_->SetBranchAddress("RivetPLs.e", &RivetPLs_e_);
      tree_->SetBranchStatus("RivetPLs.pt", 1); tree_->SetBranchAddress("RivetPLs.pt", &RivetPLs_pt_);
      tree_->SetBranchStatus("RivetPLs.eta", 1); tree_->SetBranchAddress("RivetPLs.eta", &RivetPLs_eta_);
      tree_->SetBranchStatus("RivetPLs.phi", 1); tree_->SetBranchAddress("RivetPLs.phi", &RivetPLs_phi_);
      tree_->SetBranchStatus("RivetPLs.charge", 1); tree_->SetBranchAddress("RivetPLs.charge", &RivetPLs_charge_);
      tree_->SetBranchStatus("RivetPLs.pdgId", 1); tree_->SetBranchAddress("RivetPLs.pdgId", &RivetPLs_pdgId_);
      tree_->SetBranchStatus("RivetPLs.status", 1); tree_->SetBranchAddress("RivetPLs.status", &RivetPLs_status_);
      are_RivetPLs_loaded_ = true;
      tree_->GetEntry(current_entry_);
    }
  }
  
  void loadJets(){
    if(!are_jets_loaded_){
      tree_->SetBranchStatus("jets.e", 1); tree_->SetBranchAddress("jets.e", &jets_e_);
      tree_->SetBranchStatus("jets.pt", 1); tree_->SetBranchAddress("jets.pt", &jets_pt_);
      tree_->SetBranchStatus("jets.eta", 1); tree_->SetBranchAddress("jets.eta", &jets_eta_);
      tree_->SetBranchStatus("jets.phi", 1); tree_->SetBranchAddress("jets.phi", &jets_phi_);
      tree_->SetBranchStatus("jets.charge", 1); tree_->SetBranchAddress("jets.charge", &jets_charge_);
      tree_->SetBranchStatus("jets.area", 1); tree_->SetBranchAddress("jets.area", &jets_area_);
      tree_->SetBranchStatus("jets.uncorrPt", 1); tree_->SetBranchAddress("jets.uncorrPt", &jets_uncorrPt_);
      tree_->SetBranchStatus("jets.uncorrEta", 1); tree_->SetBranchAddress("jets.uncorrEta", &jets_uncorrEta_);
      tree_->SetBranchStatus("jets.uncorrPhi", 1); tree_->SetBranchAddress("jets.uncorrPhi", &jets_uncorrPhi_);
      tree_->SetBranchStatus("jets.uncorrEnergy", 1); tree_->SetBranchAddress("jets.uncorrEnergy", &jets_uncorrEnergy_);
      tree_->SetBranchStatus("jets.chargedHadronEnergyFraction", 1); tree_->SetBranchAddress("jets.chargedHadronEnergyFraction", &jets_chargedHadronEnergyFraction_);
      tree_->SetBranchStatus("jets.neutralHadronEnergyFraction", 1); tree_->SetBranchAddress("jets.neutralHadronEnergyFraction", &jets_neutralHadronEnergyFraction_);
      tree_->SetBranchStatus("jets.chargedEmEnergyFraction", 1); tree_->SetBranchAddress("jets.chargedEmEnergyFraction", &jets_chargedEmEnergyFraction_);
      tree_->SetBranchStatus("jets.neutralEmEnergyFraction", 1); tree_->SetBranchAddress("jets.neutralEmEnergyFraction", &jets_neutralEmEnergyFraction_);
      tree_->SetBranchStatus("jets.HFHadronEnergyFraction", 1); tree_->SetBranchAddress("jets.HFHadronEnergyFraction", &jets_HFHadronEnergyFraction_);
      tree_->SetBranchStatus("jets.HFEMEnergyFraction", 1); tree_->SetBranchAddress("jets.HFEMEnergyFraction", &jets_HFEMEnergyFraction_);
      tree_->SetBranchStatus("jets.muonEnergyFraction", 1); tree_->SetBranchAddress("jets.muonEnergyFraction", &jets_muonEnergyFraction_);
      tree_->SetBranchStatus("jets.chargedMultiplicity", 1); tree_->SetBranchAddress("jets.chargedMultiplicity", &jets_chargedMultiplicity_);
      tree_->SetBranchStatus("jets.numChargedHadrons", 1); tree_->SetBranchAddress("jets.numChargedHadrons", &jets_numChargedHadrons_);
      tree_->SetBranchStatus("jets.numNeutralHadrons", 1); tree_->SetBranchAddress("jets.numNeutralHadrons", &jets_numNeutralHadrons_);
      tree_->SetBranchStatus("jets.numPhotons", 1); tree_->SetBranchAddress("jets.numPhotons", &jets_numPhotons_);
      tree_->SetBranchStatus("jets.numElectrons", 1); tree_->SetBranchAddress("jets.numElectrons", &jets_numElectrons_);
      tree_->SetBranchStatus("jets.numMuons", 1); tree_->SetBranchAddress("jets.numMuons", &jets_numMuons_);
      tree_->SetBranchStatus("jets.numForwardEMs", 1); tree_->SetBranchAddress("jets.numForwardEMs", &jets_numForwardEMs_);
      tree_->SetBranchStatus("jets.numForwardHads", 1); tree_->SetBranchAddress("jets.numForwardHads", &jets_numForwardHads_);
      tree_->SetBranchStatus("jets.numberOfDaughters", 1); tree_->SetBranchAddress("jets.numberOfDaughters", &jets_numberOfDaughters_);
      tree_->SetBranchStatus("jets.puId", 1); tree_->SetBranchAddress("jets.puId", &jets_puId_);
      tree_->SetBranchStatus("jets.csvIncl", 1); tree_->SetBranchAddress("jets.csvIncl", &jets_csvIncl_);
      tree_->SetBranchStatus("jets.CombinedMVA", 1); tree_->SetBranchAddress("jets.CombinedMVA", &jets_CombinedMVA_);
      tree_->SetBranchStatus("jets.CvsL", 1); tree_->SetBranchAddress("jets.CvsL", &jets_CvsL_);
      tree_->SetBranchStatus("jets.CvsB", 1); tree_->SetBranchAddress("jets.CvsB", &jets_CvsB_);
      tree_->SetBranchStatus("jets.DeepCSVlight", 1); tree_->SetBranchAddress("jets.DeepCSVlight", &jets_DeepCSVlight_);
      tree_->SetBranchStatus("jets.DeepCSVc", 1); tree_->SetBranchAddress("jets.DeepCSVc", &jets_DeepCSVc_);
      tree_->SetBranchStatus("jets.DeepCSVb", 1); tree_->SetBranchAddress("jets.DeepCSVb", &jets_DeepCSVb_);
      tree_->SetBranchStatus("jets.DeepCSVbb", 1); tree_->SetBranchAddress("jets.DeepCSVbb", &jets_DeepCSVbb_);
      tree_->SetBranchStatus("jets.partonFlavour", 1); tree_->SetBranchAddress("jets.partonFlavour", &jets_partonFlavour_);
      tree_->SetBranchStatus("jets.hadronFlavour", 1); tree_->SetBranchAddress("jets.hadronFlavour", &jets_hadronFlavour_);
      tree_->SetBranchStatus("jets.pupt_tight", 1); tree_->SetBranchAddress("jets.pupt_tight", &jets_pupt_tight_);
      tree_->SetBranchStatus("jets.pupt_loose", 1); tree_->SetBranchAddress("jets.pupt_loose", &jets_pupt_loose_);
      tree_->SetBranchStatus("jets.pupt_alltight", 1); tree_->SetBranchAddress("jets.pupt_alltight", &jets_pupt_alltight_);
      tree_->SetBranchStatus("jets.pupt_allloose", 1); tree_->SetBranchAddress("jets.pupt_allloose", &jets_pupt_allloose_);
      are_jets_loaded_ = true;
      tree_->GetEntry(current_entry_);
    }
  }
  
  void loadMuons(){
    if(!are_muons_loaded_){
      tree_->SetBranchStatus("muons.e", 1); tree_->SetBranchAddress("muons.e", &muons_e_);
      tree_->SetBranchStatus("muons.pt", 1); tree_->SetBranchAddress("muons.pt", &muons_pt_);
      tree_->SetBranchStatus("muons.eta", 1); tree_->SetBranchAddress("muons.eta", &muons_eta_);
      tree_->SetBranchStatus("muons.phi", 1); tree_->SetBranchAddress("muons.phi", &muons_phi_);
      tree_->SetBranchStatus("muons.charge", 1); tree_->SetBranchAddress("muons.charge", &muons_charge_);
      tree_->SetBranchStatus("muons.dB", 1); tree_->SetBranchAddress("muons.dB", &muons_dB_);
      tree_->SetBranchStatus("muons.ipDXY", 1); tree_->SetBranchAddress("muons.ipDXY", &muons_ipDXY_);
      tree_->SetBranchStatus("muons.dz", 1); tree_->SetBranchAddress("muons.dz", &muons_dz_);
      tree_->SetBranchStatus("muons.nMissingInnerHits", 1); tree_->SetBranchAddress("muons.nMissingInnerHits", &muons_nMissingInnerHits_);
      tree_->SetBranchStatus("muons.ECalEnergy", 1); tree_->SetBranchAddress("muons.ECalEnergy", &muons_ECalEnergy_);
      tree_->SetBranchStatus("muons.HCalEnergy", 1); tree_->SetBranchAddress("muons.HCalEnergy", &muons_HCalEnergy_);
      tree_->SetBranchStatus("muons.numMatchedStations", 1); tree_->SetBranchAddress("muons.numMatchedStations", &muons_numMatchedStations_);
      tree_->SetBranchStatus("muons.pfChargedIso04", 1); tree_->SetBranchAddress("muons.pfChargedIso04", &muons_pfChargedIso04_);
      tree_->SetBranchStatus("muons.pfNeutralIso04", 1); tree_->SetBranchAddress("muons.pfNeutralIso04", &muons_pfNeutralIso04_);
      tree_->SetBranchStatus("muons.pfPhotonIso04", 1); tree_->SetBranchAddress("muons.pfPhotonIso04", &muons_pfPhotonIso04_);
      tree_->SetBranchStatus("muons.pfPUIso04", 1); tree_->SetBranchAddress("muons.pfPUIso04", &muons_pfPUIso04_);
      tree_->SetBranchStatus("muons.trkIso03", 1); tree_->SetBranchAddress("muons.trkIso03", &muons_trkIso03_);
      tree_->SetBranchStatus("muons.ptErr", 1); tree_->SetBranchAddress("muons.ptErr", &muons_ptErr_);
      tree_->SetBranchStatus("muons.chi2", 1); tree_->SetBranchAddress("muons.chi2", &muons_chi2_);
      tree_->SetBranchStatus("muons.ndof", 1); tree_->SetBranchAddress("muons.ndof", &muons_ndof_);
      tree_->SetBranchStatus("muons.validHits", 1); tree_->SetBranchAddress("muons.validHits", &muons_validHits_);
      tree_->SetBranchStatus("muons.pixelHits", 1); tree_->SetBranchAddress("muons.pixelHits", &muons_pixelHits_);
      tree_->SetBranchStatus("muons.trackerLayers", 1); tree_->SetBranchAddress("muons.trackerLayers", &muons_trackerLayers_);
      tree_->SetBranchStatus("muons.isGlobal", 1); tree_->SetBranchAddress("muons.isGlobal", &muons_isGlobal_);
      tree_->SetBranchStatus("muons.isTracker", 1); tree_->SetBranchAddress("muons.isTracker", &muons_isTracker_);
      tree_->SetBranchStatus("muons.isCalo", 1); tree_->SetBranchAddress("muons.isCalo", &muons_isCalo_);
      tree_->SetBranchStatus("muons.isPF", 1); tree_->SetBranchAddress("muons.isPF", &muons_isPF_);
      tree_->SetBranchStatus("muons.isStandAlone", 1); tree_->SetBranchAddress("muons.isStandAlone", &muons_isStandAlone_);
      tree_->SetBranchStatus("muons.HLT_IsoTkMu24", 1); tree_->SetBranchAddress("muons.HLT_IsoTkMu24", &muons_HLT_IsoTkMu24_);
      tree_->SetBranchStatus("muons.HLT_IsoMu24", 1); tree_->SetBranchAddress("muons.HLT_IsoMu24", &muons_HLT_IsoMu24_);
      tree_->SetBranchStatus("muons.HLT_IsoTkMu27", 1); tree_->SetBranchAddress("muons.HLT_IsoTkMu27", &muons_HLT_IsoTkMu27_);
      tree_->SetBranchStatus("muons.HLT_IsoMu27", 1); tree_->SetBranchAddress("muons.HLT_IsoMu27", &muons_HLT_IsoMu27_);
      are_muons_loaded_ = true;
      tree_->GetEntry(current_entry_);
    }
  }
  
  void loadLhes(){
    if(!are_lhes_loaded_){
      tree_->SetBranchStatus("lhes.px", 1); tree_->SetBranchAddress("lhes.px", &lhes_px_);
      tree_->SetBranchStatus("lhes.py", 1); tree_->SetBranchAddress("lhes.py", &lhes_py_);
      tree_->SetBranchStatus("lhes.pz", 1); tree_->SetBranchAddress("lhes.pz", &lhes_pz_);
      tree_->SetBranchStatus("lhes.e", 1); tree_->SetBranchAddress("lhes.e", &lhes_e_);
      tree_->SetBranchStatus("lhes.pdgid", 1); tree_->SetBranchAddress("lhes.pdgid", &lhes_pdgid_);
      tree_->SetBranchStatus("lhes.status", 1); tree_->SetBranchAddress("lhes.status", &lhes_status_);
      tree_->SetBranchStatus("lhes.fmother", 1); tree_->SetBranchAddress("lhes.fmother", &lhes_fmother_);
      tree_->SetBranchStatus("lhes.lmother", 1); tree_->SetBranchAddress("lhes.lmother", &lhes_lmother_);
      are_lhes_loaded_ = true;
      tree_->GetEntry(current_entry_);
    }
  }
  
  void loadVertexs(){
    if(!are_vertexs_loaded_){
      tree_->SetBranchStatus("vertexs.x", 1); tree_->SetBranchAddress("vertexs.x", &vertexs_x_);
      tree_->SetBranchStatus("vertexs.y", 1); tree_->SetBranchAddress("vertexs.y", &vertexs_y_);
      tree_->SetBranchStatus("vertexs.z", 1); tree_->SetBranchAddress("vertexs.z", &vertexs_z_);
      tree_->SetBranchStatus("vertexs.chi2", 1); tree_->SetBranchAddress("vertexs.chi2", &vertexs_chi2_);
      tree_->SetBranchStatus("vertexs.ndof", 1); tree_->SetBranchAddress("vertexs.ndof", &vertexs_ndof_);
      tree_->SetBranchStatus("vertexs.nTracks", 1); tree_->SetBranchAddress("vertexs.nTracks", &vertexs_nTracks_);
      are_vertexs_loaded_ = true;
      tree_->GetEntry(current_entry_);
    }
  }
  
  void loadPuinfos(){
    if(!are_PUInfos_loaded_){
      tree_->SetBranchStatus("PUInfos.bx", 1); tree_->SetBranchAddress("PUInfos.bx", &PUInfos_bx_);
      tree_->SetBranchStatus("PUInfos.nPU", 1); tree_->SetBranchAddress("PUInfos.nPU", &PUInfos_nPU_);
      tree_->SetBranchStatus("PUInfos.nInteractions", 1); tree_->SetBranchAddress("PUInfos.nInteractions", &PUInfos_nInteractions_);
      are_PUInfos_loaded_ = true;
      tree_->GetEntry(current_entry_);
    }
  }
  

  const vector<Met>& METs(){
    if(METs_.size() > 0) return METs_;
    loadMets();
  	METs_.reserve(METs_px_->size());
    auto it_METs_px_ = METs_px_->cbegin();
    auto it_METs_py_ = METs_py_->cbegin();
    auto it_METs_pxunc_ = METs_pxunc_->cbegin();
    auto it_METs_pyunc_ = METs_pyunc_->cbegin();
    for(; it_METs_px_ != METs_px_->cend(); ){
      Met obj;
      obj.setpxunc(*it_METs_pxunc_);
      obj.setpyunc(*it_METs_pyunc_);
      obj.setLotentzVector(*it_METs_px_, *it_METs_py_);
      METs_.push_back( obj );
      ++it_METs_px_;
      ++it_METs_py_;
      ++it_METs_pxunc_;
      ++it_METs_pyunc_;
    }
    return METs_;
  }
  
  const vector<Pl>& PLs(){
    if(PLs_.size() > 0) return PLs_;
    loadPls();
  	PLs_.reserve(PLs_e_->size());
    auto it_PLs_e_ = PLs_e_->cbegin();
    auto it_PLs_pt_ = PLs_pt_->cbegin();
    auto it_PLs_eta_ = PLs_eta_->cbegin();
    auto it_PLs_phi_ = PLs_phi_->cbegin();
    auto it_PLs_charge_ = PLs_charge_->cbegin();
    auto it_PLs_pdgId_ = PLs_pdgId_->cbegin();
    auto it_PLs_status_ = PLs_status_->cbegin();
    auto it_PLs_isoR3_ = PLs_isoR3_->cbegin();
    auto it_PLs_isoR4_ = PLs_isoR4_->cbegin();
    for(; it_PLs_e_ != PLs_e_->cend(); ){
      Pl obj;
      obj.setcharge(*it_PLs_charge_);
      obj.setpdgId(*it_PLs_pdgId_);
      obj.setstatus(*it_PLs_status_);
      obj.setisoR3(*it_PLs_isoR3_);
      obj.setisoR4(*it_PLs_isoR4_);
      obj.setLotentzVector(*it_PLs_pt_, *it_PLs_eta_, *it_PLs_phi_, *it_PLs_e_);
      PLs_.push_back( obj );
      ++it_PLs_e_;
      ++it_PLs_pt_;
      ++it_PLs_eta_;
      ++it_PLs_phi_;
      ++it_PLs_charge_;
      ++it_PLs_pdgId_;
      ++it_PLs_status_;
      ++it_PLs_isoR3_;
      ++it_PLs_isoR4_;
    }
    return PLs_;
  }
  
  const vector<Mcweight>& MCWeights(){
    if(MCWeights_.size() > 0) return MCWeights_;
    loadMcweights();
  	MCWeights_.reserve(MCWeights_weights_->size());
    auto it_MCWeights_weights_ = MCWeights_weights_->cbegin();
    for(; it_MCWeights_weights_ != MCWeights_weights_->cend(); ){
      Mcweight obj;
      obj.setweights(*it_MCWeights_weights_);
      
      MCWeights_.push_back( obj );
      ++it_MCWeights_weights_;
    }
    return MCWeights_;
  }
  
  const Geninfo genInfo(){
    //non-vectorial objects are recomputed every
    //time for simplicity 
    loadGeninfo();
  
    Geninfo obj;
    obj.setweight(genInfo_weight_);
    obj.setpdfid1(genInfo_pdfid1_);
    obj.setpdfid2(genInfo_pdfid2_);
    obj.setx1(genInfo_x1_);
    obj.setx2(genInfo_x2_);
    obj.setrenScale(genInfo_renScale_);
  
    return obj;
  }
  
  const vector<Photon>& photons(){
    if(photons_.size() > 0) return photons_;
    loadPhotons();
  	photons_.reserve(photons_e_->size());
    auto it_photons_e_ = photons_e_->cbegin();
    auto it_photons_pt_ = photons_pt_->cbegin();
    auto it_photons_eta_ = photons_eta_->cbegin();
    auto it_photons_phi_ = photons_phi_->cbegin();
    auto it_photons_charge_ = photons_charge_->cbegin();
    auto it_photons_x_ = photons_x_->cbegin();
    auto it_photons_y_ = photons_y_->cbegin();
    auto it_photons_z_ = photons_z_->cbegin();
    auto it_photons_energy_ = photons_energy_->cbegin();
    auto it_photons_rawEnergy_ = photons_rawEnergy_->cbegin();
    auto it_photons_phiWidth_ = photons_phiWidth_->cbegin();
    auto it_photons_etaWidth_ = photons_etaWidth_->cbegin();
    auto it_photons_e3x3_ = photons_e3x3_->cbegin();
    auto it_photons_maxCrystalEnergy_ = photons_maxCrystalEnergy_->cbegin();
    auto it_photons_isEB_ = photons_isEB_->cbegin();
    auto it_photons_isEE_ = photons_isEE_->cbegin();
    auto it_photons_isPFlowPhoton_ = photons_isPFlowPhoton_->cbegin();
    auto it_photons_hasConversionTracks_ = photons_hasConversionTracks_->cbegin();
    auto it_photons_hasPixelSeed_ = photons_hasPixelSeed_->cbegin();
    for(; it_photons_e_ != photons_e_->cend(); ){
      Photon obj;
      obj.setcharge(*it_photons_charge_);
      obj.setx(*it_photons_x_);
      obj.sety(*it_photons_y_);
      obj.setz(*it_photons_z_);
      obj.setenergy(*it_photons_energy_);
      obj.setrawEnergy(*it_photons_rawEnergy_);
      obj.setphiWidth(*it_photons_phiWidth_);
      obj.setetaWidth(*it_photons_etaWidth_);
      obj.sete3x3(*it_photons_e3x3_);
      obj.setmaxCrystalEnergy(*it_photons_maxCrystalEnergy_);
      obj.setisEB(*it_photons_isEB_);
      obj.setisEE(*it_photons_isEE_);
      obj.setisPFlowPhoton(*it_photons_isPFlowPhoton_);
      obj.sethasConversionTracks(*it_photons_hasConversionTracks_);
      obj.sethasPixelSeed(*it_photons_hasPixelSeed_);
      obj.setLotentzVector(*it_photons_pt_, *it_photons_eta_, *it_photons_phi_, *it_photons_e_);
      photons_.push_back( obj );
      ++it_photons_e_;
      ++it_photons_pt_;
      ++it_photons_eta_;
      ++it_photons_phi_;
      ++it_photons_charge_;
      ++it_photons_x_;
      ++it_photons_y_;
      ++it_photons_z_;
      ++it_photons_energy_;
      ++it_photons_rawEnergy_;
      ++it_photons_phiWidth_;
      ++it_photons_etaWidth_;
      ++it_photons_e3x3_;
      ++it_photons_maxCrystalEnergy_;
      ++it_photons_isEB_;
      ++it_photons_isEE_;
      ++it_photons_isPFlowPhoton_;
      ++it_photons_hasConversionTracks_;
      ++it_photons_hasPixelSeed_;
    }
    return photons_;
  }
  
  const vector<Ttgen>& TTGens(){
    if(TTGens_.size() > 0) return TTGens_;
    loadTtgens();
  	TTGens_.reserve(TTGens_e_->size());
    auto it_TTGens_e_ = TTGens_e_->cbegin();
    auto it_TTGens_pt_ = TTGens_pt_->cbegin();
    auto it_TTGens_eta_ = TTGens_eta_->cbegin();
    auto it_TTGens_phi_ = TTGens_phi_->cbegin();
    auto it_TTGens_charge_ = TTGens_charge_->cbegin();
    auto it_TTGens_pdgId_ = TTGens_pdgId_->cbegin();
    auto it_TTGens_status_ = TTGens_status_->cbegin();
    for(; it_TTGens_e_ != TTGens_e_->cend(); ){
      Ttgen obj;
      obj.setcharge(*it_TTGens_charge_);
      obj.setpdgId(*it_TTGens_pdgId_);
      obj.setstatus(*it_TTGens_status_);
      obj.setLotentzVector(*it_TTGens_pt_, *it_TTGens_eta_, *it_TTGens_phi_, *it_TTGens_e_);
      TTGens_.push_back( obj );
      ++it_TTGens_e_;
      ++it_TTGens_pt_;
      ++it_TTGens_eta_;
      ++it_TTGens_phi_;
      ++it_TTGens_charge_;
      ++it_TTGens_pdgId_;
      ++it_TTGens_status_;
    }
    return TTGens_;
  }
  
  const Filter filter(){
    //non-vectorial objects are recomputed every
    //time for simplicity 
    loadFilter();
  
    Filter obj;
    obj.setFlag_goodVertices(filter_Flag_goodVertices_);
    obj.setFlag_CSCTightHaloFilter(filter_Flag_CSCTightHaloFilter_);
    obj.setFlag_trkPOGFilters(filter_Flag_trkPOGFilters_);
    obj.setFlag_trkPOG_logErrorTooManyClusters(filter_Flag_trkPOG_logErrorTooManyClusters_);
    obj.setFlag_EcalDeadCellTriggerPrimitiveFilter(filter_Flag_EcalDeadCellTriggerPrimitiveFilter_);
    obj.setFlag_ecalLaserCorrFilter(filter_Flag_ecalLaserCorrFilter_);
    obj.setFlag_trkPOG_manystripclus53X(filter_Flag_trkPOG_manystripclus53X_);
    obj.setFlag_eeBadScFilter(filter_Flag_eeBadScFilter_);
    obj.setFlag_METFilters(filter_Flag_METFilters_);
    obj.setFlag_HBHENoiseFilter(filter_Flag_HBHENoiseFilter_);
    obj.setFlag_trkPOG_toomanystripclus53X(filter_Flag_trkPOG_toomanystripclus53X_);
    obj.setFlag_hcalLaserEventFilter(filter_Flag_hcalLaserEventFilter_);
  
    return obj;
  }
  
  const Trigger trigger(){
    //non-vectorial objects are recomputed every
    //time for simplicity 
    loadTrigger();
  
    Trigger obj;
    obj.setHLT_notexists(trigger_HLT_notexists_);
    obj.setHLT_IsoTkMu24(trigger_HLT_IsoTkMu24_);
    obj.setHLT_IsoMu24(trigger_HLT_IsoMu24_);
    obj.setHLT_IsoTkMu27(trigger_HLT_IsoTkMu27_);
    obj.setHLT_IsoMu27(trigger_HLT_IsoMu27_);
    obj.setHLT_Ele27_eta2p1_WPTight_Gsf(trigger_HLT_Ele27_eta2p1_WPTight_Gsf_);
    obj.setHLT_Ele32_eta2p1_WPTight_Gsf(trigger_HLT_Ele32_eta2p1_WPTight_Gsf_);
    obj.setHLT_Ele32_WPTight_Gsf(trigger_HLT_Ele32_WPTight_Gsf_);
    obj.setHLT_Ele27_WPTight_Gsf(trigger_HLT_Ele27_WPTight_Gsf_);
    obj.setL1_SingleIsoEG34er(trigger_L1_SingleIsoEG34er_);
    obj.setL1_SingleIsoEG34(trigger_L1_SingleIsoEG34_);
    obj.setL1_SingleIsoEG32er(trigger_L1_SingleIsoEG32er_);
    obj.setL1_SingleIsoEG32(trigger_L1_SingleIsoEG32_);
    obj.setPSColumn(trigger_PSColumn_);
    obj.setEl27ptmax(trigger_El27ptmax_);
  
    return obj;
  }
  
  const vector<Electron>& electrons(){
    if(electrons_.size() > 0) return electrons_;
    loadElectrons();
  	electrons_.reserve(electrons_e_->size());
    auto it_electrons_e_ = electrons_e_->cbegin();
    auto it_electrons_pt_ = electrons_pt_->cbegin();
    auto it_electrons_eta_ = electrons_eta_->cbegin();
    auto it_electrons_phi_ = electrons_phi_->cbegin();
    auto it_electrons_charge_ = electrons_charge_->cbegin();
    auto it_electrons_dB_ = electrons_dB_->cbegin();
    auto it_electrons_ipDXY_ = electrons_ipDXY_->cbegin();
    auto it_electrons_dz_ = electrons_dz_->cbegin();
    auto it_electrons_nMissingInnerHits_ = electrons_nMissingInnerHits_->cbegin();
    auto it_electrons_SCeta_ = electrons_SCeta_->cbegin();
    auto it_electrons_DEtaSCTrk_ = electrons_DEtaSCTrk_->cbegin();
    auto it_electrons_DPhiSCTrk_ = electrons_DPhiSCTrk_->cbegin();
    auto it_electrons_ESCOverETrack_ = electrons_ESCOverETrack_->cbegin();
    auto it_electrons_ecalEnergy_ = electrons_ecalEnergy_->cbegin();
    auto it_electrons_full5x5_sigmaIEtaIEta_ = electrons_full5x5_sigmaIEtaIEta_->cbegin();
    auto it_electrons_hadronicOverEM_ = electrons_hadronicOverEM_->cbegin();
    auto it_electrons_isEB_ = electrons_isEB_->cbegin();
    auto it_electrons_isEE_ = electrons_isEE_->cbegin();
    auto it_electrons_pfChargedIso_ = electrons_pfChargedIso_->cbegin();
    auto it_electrons_pfNeutralIso_ = electrons_pfNeutralIso_->cbegin();
    auto it_electrons_pfPhotonIso_ = electrons_pfPhotonIso_->cbegin();
    auto it_electrons_pfPUIso_ = electrons_pfPUIso_->cbegin();
    auto it_electrons_HLT_Ele27_eta2p1_WPTight_Gsf_ = electrons_HLT_Ele27_eta2p1_WPTight_Gsf_->cbegin();
    auto it_electrons_HLT_Ele32_eta2p1_WPTight_Gsf_ = electrons_HLT_Ele32_eta2p1_WPTight_Gsf_->cbegin();
    auto it_electrons_HLT_Ele32_WPTight_Gsf_ = electrons_HLT_Ele32_WPTight_Gsf_->cbegin();
    auto it_electrons_HLT_Ele27_WPTight_Gsf_ = electrons_HLT_Ele27_WPTight_Gsf_->cbegin();
    auto it_electrons_conversion_ = electrons_conversion_->cbegin();
    for(; it_electrons_e_ != electrons_e_->cend(); ){
      Electron obj;
      obj.setcharge(*it_electrons_charge_);
      obj.setdB(*it_electrons_dB_);
      obj.setipDXY(*it_electrons_ipDXY_);
      obj.setdz(*it_electrons_dz_);
      obj.setnMissingInnerHits(*it_electrons_nMissingInnerHits_);
      obj.setSCeta(*it_electrons_SCeta_);
      obj.setDEtaSCTrk(*it_electrons_DEtaSCTrk_);
      obj.setDPhiSCTrk(*it_electrons_DPhiSCTrk_);
      obj.setESCOverETrack(*it_electrons_ESCOverETrack_);
      obj.setecalEnergy(*it_electrons_ecalEnergy_);
      obj.setfull5x5_sigmaIEtaIEta(*it_electrons_full5x5_sigmaIEtaIEta_);
      obj.sethadronicOverEM(*it_electrons_hadronicOverEM_);
      obj.setisEB(*it_electrons_isEB_);
      obj.setisEE(*it_electrons_isEE_);
      obj.setpfChargedIso(*it_electrons_pfChargedIso_);
      obj.setpfNeutralIso(*it_electrons_pfNeutralIso_);
      obj.setpfPhotonIso(*it_electrons_pfPhotonIso_);
      obj.setpfPUIso(*it_electrons_pfPUIso_);
      obj.setHLT_Ele27_eta2p1_WPTight_Gsf(*it_electrons_HLT_Ele27_eta2p1_WPTight_Gsf_);
      obj.setHLT_Ele32_eta2p1_WPTight_Gsf(*it_electrons_HLT_Ele32_eta2p1_WPTight_Gsf_);
      obj.setHLT_Ele32_WPTight_Gsf(*it_electrons_HLT_Ele32_WPTight_Gsf_);
      obj.setHLT_Ele27_WPTight_Gsf(*it_electrons_HLT_Ele27_WPTight_Gsf_);
      obj.setconversion(*it_electrons_conversion_);
      obj.setLotentzVector(*it_electrons_pt_, *it_electrons_eta_, *it_electrons_phi_, *it_electrons_e_);
      electrons_.push_back( obj );
      ++it_electrons_e_;
      ++it_electrons_pt_;
      ++it_electrons_eta_;
      ++it_electrons_phi_;
      ++it_electrons_charge_;
      ++it_electrons_dB_;
      ++it_electrons_ipDXY_;
      ++it_electrons_dz_;
      ++it_electrons_nMissingInnerHits_;
      ++it_electrons_SCeta_;
      ++it_electrons_DEtaSCTrk_;
      ++it_electrons_DPhiSCTrk_;
      ++it_electrons_ESCOverETrack_;
      ++it_electrons_ecalEnergy_;
      ++it_electrons_full5x5_sigmaIEtaIEta_;
      ++it_electrons_hadronicOverEM_;
      ++it_electrons_isEB_;
      ++it_electrons_isEE_;
      ++it_electrons_pfChargedIso_;
      ++it_electrons_pfNeutralIso_;
      ++it_electrons_pfPhotonIso_;
      ++it_electrons_pfPUIso_;
      ++it_electrons_HLT_Ele27_eta2p1_WPTight_Gsf_;
      ++it_electrons_HLT_Ele32_eta2p1_WPTight_Gsf_;
      ++it_electrons_HLT_Ele32_WPTight_Gsf_;
      ++it_electrons_HLT_Ele27_WPTight_Gsf_;
      ++it_electrons_conversion_;
    }
    return electrons_;
  }
  
  const Rho rho(){
    //non-vectorial objects are recomputed every
    //time for simplicity 
    loadRho();
  
    Rho obj;
    obj.setvalue(rho_value_);
  
    return obj;
  }
  
  const vector<Rivetpl>& RivetPLs(){
    if(RivetPLs_.size() > 0) return RivetPLs_;
    loadRivetpls();
  	RivetPLs_.reserve(RivetPLs_e_->size());
    auto it_RivetPLs_e_ = RivetPLs_e_->cbegin();
    auto it_RivetPLs_pt_ = RivetPLs_pt_->cbegin();
    auto it_RivetPLs_eta_ = RivetPLs_eta_->cbegin();
    auto it_RivetPLs_phi_ = RivetPLs_phi_->cbegin();
    auto it_RivetPLs_charge_ = RivetPLs_charge_->cbegin();
    auto it_RivetPLs_pdgId_ = RivetPLs_pdgId_->cbegin();
    auto it_RivetPLs_status_ = RivetPLs_status_->cbegin();
    for(; it_RivetPLs_e_ != RivetPLs_e_->cend(); ){
      Rivetpl obj;
      obj.setcharge(*it_RivetPLs_charge_);
      obj.setpdgId(*it_RivetPLs_pdgId_);
      obj.setstatus(*it_RivetPLs_status_);
      obj.setLotentzVector(*it_RivetPLs_pt_, *it_RivetPLs_eta_, *it_RivetPLs_phi_, *it_RivetPLs_e_);
      RivetPLs_.push_back( obj );
      ++it_RivetPLs_e_;
      ++it_RivetPLs_pt_;
      ++it_RivetPLs_eta_;
      ++it_RivetPLs_phi_;
      ++it_RivetPLs_charge_;
      ++it_RivetPLs_pdgId_;
      ++it_RivetPLs_status_;
    }
    return RivetPLs_;
  }
  
  const vector<Jet>& jets(){
    if(jets_.size() > 0) return jets_;
    loadJets();
  	jets_.reserve(jets_e_->size());
    auto it_jets_e_ = jets_e_->cbegin();
    auto it_jets_pt_ = jets_pt_->cbegin();
    auto it_jets_eta_ = jets_eta_->cbegin();
    auto it_jets_phi_ = jets_phi_->cbegin();
    auto it_jets_charge_ = jets_charge_->cbegin();
    auto it_jets_area_ = jets_area_->cbegin();
    auto it_jets_uncorrPt_ = jets_uncorrPt_->cbegin();
    auto it_jets_uncorrEta_ = jets_uncorrEta_->cbegin();
    auto it_jets_uncorrPhi_ = jets_uncorrPhi_->cbegin();
    auto it_jets_uncorrEnergy_ = jets_uncorrEnergy_->cbegin();
    auto it_jets_chargedHadronEnergyFraction_ = jets_chargedHadronEnergyFraction_->cbegin();
    auto it_jets_neutralHadronEnergyFraction_ = jets_neutralHadronEnergyFraction_->cbegin();
    auto it_jets_chargedEmEnergyFraction_ = jets_chargedEmEnergyFraction_->cbegin();
    auto it_jets_neutralEmEnergyFraction_ = jets_neutralEmEnergyFraction_->cbegin();
    auto it_jets_HFHadronEnergyFraction_ = jets_HFHadronEnergyFraction_->cbegin();
    auto it_jets_HFEMEnergyFraction_ = jets_HFEMEnergyFraction_->cbegin();
    auto it_jets_muonEnergyFraction_ = jets_muonEnergyFraction_->cbegin();
    auto it_jets_chargedMultiplicity_ = jets_chargedMultiplicity_->cbegin();
    auto it_jets_numChargedHadrons_ = jets_numChargedHadrons_->cbegin();
    auto it_jets_numNeutralHadrons_ = jets_numNeutralHadrons_->cbegin();
    auto it_jets_numPhotons_ = jets_numPhotons_->cbegin();
    auto it_jets_numElectrons_ = jets_numElectrons_->cbegin();
    auto it_jets_numMuons_ = jets_numMuons_->cbegin();
    auto it_jets_numForwardEMs_ = jets_numForwardEMs_->cbegin();
    auto it_jets_numForwardHads_ = jets_numForwardHads_->cbegin();
    auto it_jets_numberOfDaughters_ = jets_numberOfDaughters_->cbegin();
    auto it_jets_puId_ = jets_puId_->cbegin();
    auto it_jets_csvIncl_ = jets_csvIncl_->cbegin();
    auto it_jets_CombinedMVA_ = jets_CombinedMVA_->cbegin();
    auto it_jets_CvsL_ = jets_CvsL_->cbegin();
    auto it_jets_CvsB_ = jets_CvsB_->cbegin();
    auto it_jets_DeepCSVlight_ = jets_DeepCSVlight_->cbegin();
    auto it_jets_DeepCSVc_ = jets_DeepCSVc_->cbegin();
    auto it_jets_DeepCSVb_ = jets_DeepCSVb_->cbegin();
    auto it_jets_DeepCSVbb_ = jets_DeepCSVbb_->cbegin();
    auto it_jets_partonFlavour_ = jets_partonFlavour_->cbegin();
    auto it_jets_hadronFlavour_ = jets_hadronFlavour_->cbegin();
    auto it_jets_pupt_tight_ = jets_pupt_tight_->cbegin();
    auto it_jets_pupt_loose_ = jets_pupt_loose_->cbegin();
    auto it_jets_pupt_alltight_ = jets_pupt_alltight_->cbegin();
    auto it_jets_pupt_allloose_ = jets_pupt_allloose_->cbegin();
    for(; it_jets_e_ != jets_e_->cend(); ){
      Jet obj;
      obj.setcharge(*it_jets_charge_);
      obj.setarea(*it_jets_area_);
      obj.setuncorrPt(*it_jets_uncorrPt_);
      obj.setuncorrEta(*it_jets_uncorrEta_);
      obj.setuncorrPhi(*it_jets_uncorrPhi_);
      obj.setuncorrEnergy(*it_jets_uncorrEnergy_);
      obj.setchargedHadronEnergyFraction(*it_jets_chargedHadronEnergyFraction_);
      obj.setneutralHadronEnergyFraction(*it_jets_neutralHadronEnergyFraction_);
      obj.setchargedEmEnergyFraction(*it_jets_chargedEmEnergyFraction_);
      obj.setneutralEmEnergyFraction(*it_jets_neutralEmEnergyFraction_);
      obj.setHFHadronEnergyFraction(*it_jets_HFHadronEnergyFraction_);
      obj.setHFEMEnergyFraction(*it_jets_HFEMEnergyFraction_);
      obj.setmuonEnergyFraction(*it_jets_muonEnergyFraction_);
      obj.setchargedMultiplicity(*it_jets_chargedMultiplicity_);
      obj.setnumChargedHadrons(*it_jets_numChargedHadrons_);
      obj.setnumNeutralHadrons(*it_jets_numNeutralHadrons_);
      obj.setnumPhotons(*it_jets_numPhotons_);
      obj.setnumElectrons(*it_jets_numElectrons_);
      obj.setnumMuons(*it_jets_numMuons_);
      obj.setnumForwardEMs(*it_jets_numForwardEMs_);
      obj.setnumForwardHads(*it_jets_numForwardHads_);
      obj.setnumberOfDaughters(*it_jets_numberOfDaughters_);
      obj.setpuId(*it_jets_puId_);
      obj.setcsvIncl(*it_jets_csvIncl_);
      obj.setCombinedMVA(*it_jets_CombinedMVA_);
      obj.setCvsL(*it_jets_CvsL_);
      obj.setCvsB(*it_jets_CvsB_);
      obj.setDeepCSVlight(*it_jets_DeepCSVlight_);
      obj.setDeepCSVc(*it_jets_DeepCSVc_);
      obj.setDeepCSVb(*it_jets_DeepCSVb_);
      obj.setDeepCSVbb(*it_jets_DeepCSVbb_);
      obj.setpartonFlavour(*it_jets_partonFlavour_);
      obj.sethadronFlavour(*it_jets_hadronFlavour_);
      obj.setpupt_tight(*it_jets_pupt_tight_);
      obj.setpupt_loose(*it_jets_pupt_loose_);
      obj.setpupt_alltight(*it_jets_pupt_alltight_);
      obj.setpupt_allloose(*it_jets_pupt_allloose_);
      obj.setLotentzVector(*it_jets_pt_, *it_jets_eta_, *it_jets_phi_, *it_jets_e_);
      jets_.push_back( obj );
      ++it_jets_e_;
      ++it_jets_pt_;
      ++it_jets_eta_;
      ++it_jets_phi_;
      ++it_jets_charge_;
      ++it_jets_area_;
      ++it_jets_uncorrPt_;
      ++it_jets_uncorrEta_;
      ++it_jets_uncorrPhi_;
      ++it_jets_uncorrEnergy_;
      ++it_jets_chargedHadronEnergyFraction_;
      ++it_jets_neutralHadronEnergyFraction_;
      ++it_jets_chargedEmEnergyFraction_;
      ++it_jets_neutralEmEnergyFraction_;
      ++it_jets_HFHadronEnergyFraction_;
      ++it_jets_HFEMEnergyFraction_;
      ++it_jets_muonEnergyFraction_;
      ++it_jets_chargedMultiplicity_;
      ++it_jets_numChargedHadrons_;
      ++it_jets_numNeutralHadrons_;
      ++it_jets_numPhotons_;
      ++it_jets_numElectrons_;
      ++it_jets_numMuons_;
      ++it_jets_numForwardEMs_;
      ++it_jets_numForwardHads_;
      ++it_jets_numberOfDaughters_;
      ++it_jets_puId_;
      ++it_jets_csvIncl_;
      ++it_jets_CombinedMVA_;
      ++it_jets_CvsL_;
      ++it_jets_CvsB_;
      ++it_jets_DeepCSVlight_;
      ++it_jets_DeepCSVc_;
      ++it_jets_DeepCSVb_;
      ++it_jets_DeepCSVbb_;
      ++it_jets_partonFlavour_;
      ++it_jets_hadronFlavour_;
      ++it_jets_pupt_tight_;
      ++it_jets_pupt_loose_;
      ++it_jets_pupt_alltight_;
      ++it_jets_pupt_allloose_;
    }
    return jets_;
  }
  
  const vector<Muon>& muons(){
    if(muons_.size() > 0) return muons_;
    loadMuons();
  	muons_.reserve(muons_e_->size());
    auto it_muons_e_ = muons_e_->cbegin();
    auto it_muons_pt_ = muons_pt_->cbegin();
    auto it_muons_eta_ = muons_eta_->cbegin();
    auto it_muons_phi_ = muons_phi_->cbegin();
    auto it_muons_charge_ = muons_charge_->cbegin();
    auto it_muons_dB_ = muons_dB_->cbegin();
    auto it_muons_ipDXY_ = muons_ipDXY_->cbegin();
    auto it_muons_dz_ = muons_dz_->cbegin();
    auto it_muons_nMissingInnerHits_ = muons_nMissingInnerHits_->cbegin();
    auto it_muons_ECalEnergy_ = muons_ECalEnergy_->cbegin();
    auto it_muons_HCalEnergy_ = muons_HCalEnergy_->cbegin();
    auto it_muons_numMatchedStations_ = muons_numMatchedStations_->cbegin();
    auto it_muons_pfChargedIso04_ = muons_pfChargedIso04_->cbegin();
    auto it_muons_pfNeutralIso04_ = muons_pfNeutralIso04_->cbegin();
    auto it_muons_pfPhotonIso04_ = muons_pfPhotonIso04_->cbegin();
    auto it_muons_pfPUIso04_ = muons_pfPUIso04_->cbegin();
    auto it_muons_trkIso03_ = muons_trkIso03_->cbegin();
    auto it_muons_ptErr_ = muons_ptErr_->cbegin();
    auto it_muons_chi2_ = muons_chi2_->cbegin();
    auto it_muons_ndof_ = muons_ndof_->cbegin();
    auto it_muons_validHits_ = muons_validHits_->cbegin();
    auto it_muons_pixelHits_ = muons_pixelHits_->cbegin();
    auto it_muons_trackerLayers_ = muons_trackerLayers_->cbegin();
    auto it_muons_isGlobal_ = muons_isGlobal_->cbegin();
    auto it_muons_isTracker_ = muons_isTracker_->cbegin();
    auto it_muons_isCalo_ = muons_isCalo_->cbegin();
    auto it_muons_isPF_ = muons_isPF_->cbegin();
    auto it_muons_isStandAlone_ = muons_isStandAlone_->cbegin();
    auto it_muons_HLT_IsoTkMu24_ = muons_HLT_IsoTkMu24_->cbegin();
    auto it_muons_HLT_IsoMu24_ = muons_HLT_IsoMu24_->cbegin();
    auto it_muons_HLT_IsoTkMu27_ = muons_HLT_IsoTkMu27_->cbegin();
    auto it_muons_HLT_IsoMu27_ = muons_HLT_IsoMu27_->cbegin();
    for(; it_muons_e_ != muons_e_->cend(); ){
      Muon obj;
      obj.setcharge(*it_muons_charge_);
      obj.setdB(*it_muons_dB_);
      obj.setipDXY(*it_muons_ipDXY_);
      obj.setdz(*it_muons_dz_);
      obj.setnMissingInnerHits(*it_muons_nMissingInnerHits_);
      obj.setECalEnergy(*it_muons_ECalEnergy_);
      obj.setHCalEnergy(*it_muons_HCalEnergy_);
      obj.setnumMatchedStations(*it_muons_numMatchedStations_);
      obj.setpfChargedIso04(*it_muons_pfChargedIso04_);
      obj.setpfNeutralIso04(*it_muons_pfNeutralIso04_);
      obj.setpfPhotonIso04(*it_muons_pfPhotonIso04_);
      obj.setpfPUIso04(*it_muons_pfPUIso04_);
      obj.settrkIso03(*it_muons_trkIso03_);
      obj.setptErr(*it_muons_ptErr_);
      obj.setchi2(*it_muons_chi2_);
      obj.setndof(*it_muons_ndof_);
      obj.setvalidHits(*it_muons_validHits_);
      obj.setpixelHits(*it_muons_pixelHits_);
      obj.settrackerLayers(*it_muons_trackerLayers_);
      obj.setisGlobal(*it_muons_isGlobal_);
      obj.setisTracker(*it_muons_isTracker_);
      obj.setisCalo(*it_muons_isCalo_);
      obj.setisPF(*it_muons_isPF_);
      obj.setisStandAlone(*it_muons_isStandAlone_);
      obj.setHLT_IsoTkMu24(*it_muons_HLT_IsoTkMu24_);
      obj.setHLT_IsoMu24(*it_muons_HLT_IsoMu24_);
      obj.setHLT_IsoTkMu27(*it_muons_HLT_IsoTkMu27_);
      obj.setHLT_IsoMu27(*it_muons_HLT_IsoMu27_);
      obj.setLotentzVector(*it_muons_pt_, *it_muons_eta_, *it_muons_phi_, *it_muons_e_);
      muons_.push_back( obj );
      ++it_muons_e_;
      ++it_muons_pt_;
      ++it_muons_eta_;
      ++it_muons_phi_;
      ++it_muons_charge_;
      ++it_muons_dB_;
      ++it_muons_ipDXY_;
      ++it_muons_dz_;
      ++it_muons_nMissingInnerHits_;
      ++it_muons_ECalEnergy_;
      ++it_muons_HCalEnergy_;
      ++it_muons_numMatchedStations_;
      ++it_muons_pfChargedIso04_;
      ++it_muons_pfNeutralIso04_;
      ++it_muons_pfPhotonIso04_;
      ++it_muons_pfPUIso04_;
      ++it_muons_trkIso03_;
      ++it_muons_ptErr_;
      ++it_muons_chi2_;
      ++it_muons_ndof_;
      ++it_muons_validHits_;
      ++it_muons_pixelHits_;
      ++it_muons_trackerLayers_;
      ++it_muons_isGlobal_;
      ++it_muons_isTracker_;
      ++it_muons_isCalo_;
      ++it_muons_isPF_;
      ++it_muons_isStandAlone_;
      ++it_muons_HLT_IsoTkMu24_;
      ++it_muons_HLT_IsoMu24_;
      ++it_muons_HLT_IsoTkMu27_;
      ++it_muons_HLT_IsoMu27_;
    }
    return muons_;
  }
  
  const vector<Lhe>& lhes(){
    if(lhes_.size() > 0) return lhes_;
    loadLhes();
  	lhes_.reserve(lhes_px_->size());
    auto it_lhes_px_ = lhes_px_->cbegin();
    auto it_lhes_py_ = lhes_py_->cbegin();
    auto it_lhes_pz_ = lhes_pz_->cbegin();
    auto it_lhes_e_ = lhes_e_->cbegin();
    auto it_lhes_pdgid_ = lhes_pdgid_->cbegin();
    auto it_lhes_status_ = lhes_status_->cbegin();
    auto it_lhes_fmother_ = lhes_fmother_->cbegin();
    auto it_lhes_lmother_ = lhes_lmother_->cbegin();
    for(; it_lhes_px_ != lhes_px_->cend(); ){
      Lhe obj;
      obj.setpdgid(*it_lhes_pdgid_);
      obj.setstatus(*it_lhes_status_);
      obj.setfmother(*it_lhes_fmother_);
      obj.setlmother(*it_lhes_lmother_);
      obj.setLotentzVector(*it_lhes_px_, *it_lhes_py_, *it_lhes_pz_, *it_lhes_e_);
      lhes_.push_back( obj );
      ++it_lhes_px_;
      ++it_lhes_py_;
      ++it_lhes_pz_;
      ++it_lhes_e_;
      ++it_lhes_pdgid_;
      ++it_lhes_status_;
      ++it_lhes_fmother_;
      ++it_lhes_lmother_;
    }
    return lhes_;
  }
  
  const vector<Vertex>& vertexs(){
    if(vertexs_.size() > 0) return vertexs_;
    loadVertexs();
  	vertexs_.reserve(vertexs_x_->size());
    auto it_vertexs_x_ = vertexs_x_->cbegin();
    auto it_vertexs_y_ = vertexs_y_->cbegin();
    auto it_vertexs_z_ = vertexs_z_->cbegin();
    auto it_vertexs_chi2_ = vertexs_chi2_->cbegin();
    auto it_vertexs_ndof_ = vertexs_ndof_->cbegin();
    auto it_vertexs_nTracks_ = vertexs_nTracks_->cbegin();
    for(; it_vertexs_x_ != vertexs_x_->cend(); ){
      Vertex obj;
      obj.setx(*it_vertexs_x_);
      obj.sety(*it_vertexs_y_);
      obj.setz(*it_vertexs_z_);
      obj.setchi2(*it_vertexs_chi2_);
      obj.setndof(*it_vertexs_ndof_);
      obj.setnTracks(*it_vertexs_nTracks_);
      
      vertexs_.push_back( obj );
      ++it_vertexs_x_;
      ++it_vertexs_y_;
      ++it_vertexs_z_;
      ++it_vertexs_chi2_;
      ++it_vertexs_ndof_;
      ++it_vertexs_nTracks_;
    }
    return vertexs_;
  }
  
  const vector<Puinfo>& PUInfos(){
    if(PUInfos_.size() > 0) return PUInfos_;
    loadPuinfos();
  	PUInfos_.reserve(PUInfos_bx_->size());
    auto it_PUInfos_bx_ = PUInfos_bx_->cbegin();
    auto it_PUInfos_nPU_ = PUInfos_nPU_->cbegin();
    auto it_PUInfos_nInteractions_ = PUInfos_nInteractions_->cbegin();
    for(; it_PUInfos_bx_ != PUInfos_bx_->cend(); ){
      Puinfo obj;
      obj.setbx(*it_PUInfos_bx_);
      obj.setnPU(*it_PUInfos_nPU_);
      obj.setnInteractions(*it_PUInfos_nInteractions_);
      
      PUInfos_.push_back( obj );
      ++it_PUInfos_bx_;
      ++it_PUInfos_nPU_;
      ++it_PUInfos_nInteractions_;
    }
    return PUInfos_;
  }
  

private:
  TTree *tree_;
  Long64_t entries_;
  Long64_t current_entry_;
  Int_t trigger_HLT_notexists_;
  Int_t trigger_HLT_IsoTkMu24_;
  Int_t trigger_HLT_IsoMu24_;
  Int_t trigger_HLT_IsoTkMu27_;
  Int_t trigger_HLT_IsoMu27_;
  Int_t trigger_HLT_Ele27_eta2p1_WPTight_Gsf_;
  Int_t trigger_HLT_Ele32_eta2p1_WPTight_Gsf_;
  Int_t trigger_HLT_Ele32_WPTight_Gsf_;
  Int_t trigger_HLT_Ele27_WPTight_Gsf_;
  Int_t trigger_L1_SingleIsoEG34er_;
  Int_t trigger_L1_SingleIsoEG34_;
  Int_t trigger_L1_SingleIsoEG32er_;
  Int_t trigger_L1_SingleIsoEG32_;
  Int_t trigger_PSColumn_;
  Int_t trigger_El27ptmax_;
  Int_t filter_Flag_goodVertices_;
  Int_t filter_Flag_CSCTightHaloFilter_;
  Int_t filter_Flag_trkPOGFilters_;
  Int_t filter_Flag_trkPOG_logErrorTooManyClusters_;
  Int_t filter_Flag_EcalDeadCellTriggerPrimitiveFilter_;
  Int_t filter_Flag_ecalLaserCorrFilter_;
  Int_t filter_Flag_trkPOG_manystripclus53X_;
  Int_t filter_Flag_eeBadScFilter_;
  Int_t filter_Flag_METFilters_;
  Int_t filter_Flag_HBHENoiseFilter_;
  Int_t filter_Flag_trkPOG_toomanystripclus53X_;
  Int_t filter_Flag_hcalLaserEventFilter_;
  Double_t rho_value_;
  vector<float> *muons_e_;
  vector<float> *muons_pt_;
  vector<float> *muons_eta_;
  vector<float> *muons_phi_;
  vector<int> *muons_charge_;
  vector<float> *muons_dB_;
  vector<float> *muons_ipDXY_;
  vector<float> *muons_dz_;
  vector<float> *muons_nMissingInnerHits_;
  vector<float> *muons_ECalEnergy_;
  vector<float> *muons_HCalEnergy_;
  vector<int> *muons_numMatchedStations_;
  vector<float> *muons_pfChargedIso04_;
  vector<float> *muons_pfNeutralIso04_;
  vector<float> *muons_pfPhotonIso04_;
  vector<float> *muons_pfPUIso04_;
  vector<float> *muons_trkIso03_;
  vector<float> *muons_ptErr_;
  vector<float> *muons_chi2_;
  vector<int> *muons_ndof_;
  vector<float> *muons_validHits_;
  vector<float> *muons_pixelHits_;
  vector<float> *muons_trackerLayers_;
  vector<bool> *muons_isGlobal_;
  vector<bool> *muons_isTracker_;
  vector<bool> *muons_isCalo_;
  vector<bool> *muons_isPF_;
  vector<bool> *muons_isStandAlone_;
  vector<bool> *muons_HLT_IsoTkMu24_;
  vector<bool> *muons_HLT_IsoMu24_;
  vector<bool> *muons_HLT_IsoTkMu27_;
  vector<bool> *muons_HLT_IsoMu27_;
  vector<float> *jets_e_;
  vector<float> *jets_pt_;
  vector<float> *jets_eta_;
  vector<float> *jets_phi_;
  vector<int> *jets_charge_;
  vector<float> *jets_area_;
  vector<float> *jets_uncorrPt_;
  vector<float> *jets_uncorrEta_;
  vector<float> *jets_uncorrPhi_;
  vector<float> *jets_uncorrEnergy_;
  vector<float> *jets_chargedHadronEnergyFraction_;
  vector<float> *jets_neutralHadronEnergyFraction_;
  vector<float> *jets_chargedEmEnergyFraction_;
  vector<float> *jets_neutralEmEnergyFraction_;
  vector<float> *jets_HFHadronEnergyFraction_;
  vector<float> *jets_HFEMEnergyFraction_;
  vector<float> *jets_muonEnergyFraction_;
  vector<float> *jets_chargedMultiplicity_;
  vector<float> *jets_numChargedHadrons_;
  vector<float> *jets_numNeutralHadrons_;
  vector<float> *jets_numPhotons_;
  vector<float> *jets_numElectrons_;
  vector<float> *jets_numMuons_;
  vector<float> *jets_numForwardEMs_;
  vector<float> *jets_numForwardHads_;
  vector<float> *jets_numberOfDaughters_;
  vector<float> *jets_puId_;
  vector<float> *jets_csvIncl_;
  vector<float> *jets_CombinedMVA_;
  vector<float> *jets_CvsL_;
  vector<float> *jets_CvsB_;
  vector<float> *jets_DeepCSVlight_;
  vector<float> *jets_DeepCSVc_;
  vector<float> *jets_DeepCSVb_;
  vector<float> *jets_DeepCSVbb_;
  vector<int> *jets_partonFlavour_;
  vector<int> *jets_hadronFlavour_;
  vector<float> *jets_pupt_tight_;
  vector<float> *jets_pupt_loose_;
  vector<float> *jets_pupt_alltight_;
  vector<float> *jets_pupt_allloose_;
  vector<float> *electrons_e_;
  vector<float> *electrons_pt_;
  vector<float> *electrons_eta_;
  vector<float> *electrons_phi_;
  vector<int> *electrons_charge_;
  vector<float> *electrons_dB_;
  vector<float> *electrons_ipDXY_;
  vector<float> *electrons_dz_;
  vector<float> *electrons_nMissingInnerHits_;
  vector<float> *electrons_SCeta_;
  vector<float> *electrons_DEtaSCTrk_;
  vector<float> *electrons_DPhiSCTrk_;
  vector<float> *electrons_ESCOverETrack_;
  vector<float> *electrons_ecalEnergy_;
  vector<float> *electrons_full5x5_sigmaIEtaIEta_;
  vector<float> *electrons_hadronicOverEM_;
  vector<bool> *electrons_isEB_;
  vector<bool> *electrons_isEE_;
  vector<float> *electrons_pfChargedIso_;
  vector<float> *electrons_pfNeutralIso_;
  vector<float> *electrons_pfPhotonIso_;
  vector<float> *electrons_pfPUIso_;
  vector<bool> *electrons_HLT_Ele27_eta2p1_WPTight_Gsf_;
  vector<bool> *electrons_HLT_Ele32_eta2p1_WPTight_Gsf_;
  vector<bool> *electrons_HLT_Ele32_WPTight_Gsf_;
  vector<bool> *electrons_HLT_Ele27_WPTight_Gsf_;
  vector<bool> *electrons_conversion_;
  vector<float> *photons_e_;
  vector<float> *photons_pt_;
  vector<float> *photons_eta_;
  vector<float> *photons_phi_;
  vector<int> *photons_charge_;
  vector<float> *photons_x_;
  vector<float> *photons_y_;
  vector<float> *photons_z_;
  vector<float> *photons_energy_;
  vector<float> *photons_rawEnergy_;
  vector<float> *photons_phiWidth_;
  vector<float> *photons_etaWidth_;
  vector<float> *photons_e3x3_;
  vector<float> *photons_maxCrystalEnergy_;
  vector<bool> *photons_isEB_;
  vector<bool> *photons_isEE_;
  vector<bool> *photons_isPFlowPhoton_;
  vector<bool> *photons_hasConversionTracks_;
  vector<bool> *photons_hasPixelSeed_;
  vector<float> *vertexs_x_;
  vector<float> *vertexs_y_;
  vector<float> *vertexs_z_;
  vector<float> *vertexs_chi2_;
  vector<float> *vertexs_ndof_;
  vector<float> *vertexs_nTracks_;
  vector<float> *METs_px_;
  vector<float> *METs_py_;
  vector<float> *METs_pxunc_;
  vector<float> *METs_pyunc_;
  Float_t genInfo_weight_;
  Float_t genInfo_pdfid1_;
  Float_t genInfo_pdfid2_;
  Float_t genInfo_x1_;
  Float_t genInfo_x2_;
  Float_t genInfo_renScale_;
  vector<float> *MCWeights_weights_;
  vector<float> *lhes_px_;
  vector<float> *lhes_py_;
  vector<float> *lhes_pz_;
  vector<float> *lhes_e_;
  vector<int> *lhes_pdgid_;
  vector<int> *lhes_status_;
  vector<int> *lhes_fmother_;
  vector<int> *lhes_lmother_;
  vector<float> *PUInfos_bx_;
  vector<float> *PUInfos_nPU_;
  vector<float> *PUInfos_nInteractions_;
  vector<float> *PLs_e_;
  vector<float> *PLs_pt_;
  vector<float> *PLs_eta_;
  vector<float> *PLs_phi_;
  vector<int> *PLs_charge_;
  vector<int> *PLs_pdgId_;
  vector<int> *PLs_status_;
  vector<float> *PLs_isoR3_;
  vector<float> *PLs_isoR4_;
  vector<float> *RivetPLs_e_;
  vector<float> *RivetPLs_pt_;
  vector<float> *RivetPLs_eta_;
  vector<float> *RivetPLs_phi_;
  vector<int> *RivetPLs_charge_;
  vector<int> *RivetPLs_pdgId_;
  vector<int> *RivetPLs_status_;
  vector<float> *TTGens_e_;
  vector<float> *TTGens_pt_;
  vector<float> *TTGens_eta_;
  vector<float> *TTGens_phi_;
  vector<int> *TTGens_charge_;
  vector<int> *TTGens_pdgId_;
  vector<int> *TTGens_status_;
  bool are_METs_loaded_;
  vector<Met> METs_;
  bool are_PLs_loaded_;
  vector<Pl> PLs_;
  bool are_MCWeights_loaded_;
  vector<Mcweight> MCWeights_;
  bool are_genInfo_loaded_;
  Geninfo genInfo_;
  bool are_photons_loaded_;
  vector<Photon> photons_;
  bool are_TTGens_loaded_;
  vector<Ttgen> TTGens_;
  bool are_filter_loaded_;
  Filter filter_;
  bool are_trigger_loaded_;
  Trigger trigger_;
  bool are_electrons_loaded_;
  vector<Electron> electrons_;
  bool are_rho_loaded_;
  Rho rho_;
  bool are_RivetPLs_loaded_;
  vector<Rivetpl> RivetPLs_;
  bool are_jets_loaded_;
  vector<Jet> jets_;
  bool are_muons_loaded_;
  vector<Muon> muons_;
  bool are_lhes_loaded_;
  vector<Lhe> lhes_;
  bool are_vertexs_loaded_;
  vector<Vertex> vertexs_;
  bool are_PUInfos_loaded_;
  vector<Puinfo> PUInfos_;
};

/*#include <iostream>
int test()
{
  TFile *f = TFile::Open("test_ntuple.root");
  TTree *t = (TTree*) f->Get("ntuple/events");
  URStreamer s(t);
  for(int i =0; i < 30; i++){
    s.next();
    vector<Muon> muons = s.muons();
    std::cout<< muons.size() << std::endl;
    for(int j=0; j<muons.size(); ++j){
      std::cout<< *(muons[j].pt) << "  ";
    }
    std::cout<< std::endl;
  }
  return 0;
  }*/

/*#ifdef __CINT__
#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;

#pragma link C++ class vector+;
#pragma link C++ class URStreamer+;
{ LINK_OBJECTS }

#endif*/
#endif

