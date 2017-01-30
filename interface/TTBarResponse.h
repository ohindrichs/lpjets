#ifndef RESPONSE
#define RESPONSE
#include <helper.h>
#include <vector>
#include <string>

using namespace std;

class ttbar;
class TDirectory;

class TTBarResponse
{
	protected:
		string prefix_;
		ttbar* an_;
		TDirectory* dir;
		TH1DCollection plot1d;	
		TH2DCollection plot2d;
		map<string, bool> withext;

	public:
		TTBarResponse(string prefix, ttbar* an);
		~TTBarResponse();
		void AddMatrix(string name, const vector<double>& Mbins, const vector<double>& Tbins, string label, bool ext = false);
		void FillTruth(string name, double val, double weight);
		void FillAll(string name, double val, double weight);
		void FillBKG(string name, double val, double weight);
		void FillTruthReco(string name, double tval, double rval, double weight);
		void FillRes(string name, double tval, double rval, double weight);
};

#endif
