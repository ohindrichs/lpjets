#ifndef HJETSCALER
#define HJETSCALER
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include <algorithm>

#include "helper.h"

using namespace std;

class ttbar;
class TH1D;
class TGraph;
class TFile;


class JetScaler
{
	private:
		ttbar* AN = nullptr;
		vector<TH1D*> HptsPqcd;
		vector<TH1D*> HptsMqcd;
		TH1D* Hetaqcd = nullptr;
		vector<TH1D*> HptsPb;
		vector<TH1D*> HptsMb;
		TH1D* Hetab = nullptr;
		TFile* tf = nullptr;
		TGraph* hlE =nullptr;
		TGraph* hlB =nullptr;
		TGraph* hbE =nullptr;
		TGraph* hbB =nullptr;

		map< Bin, map<Bin, vector<double> > > resinfo;
		map< Bin, vector<double> > ressf;

	public:
		void InitMCrescale(ttbar* an, const string rescalefilename);

		void InitResolution(const string& resolutionfile, const string& sffile);

		void Init(const string& filename, const string& type, bool bjet);

		double GetRes(const IDJet& jet, double rho, double sigmares = 0.);
		double GetScale(const IDJet& jet, double sigmascale = 0.);
};


#endif
