#ifndef CTSWEIGHTS_H
#define CTSWEIGHTS_H
#include "URStreamer.h"
#include "helper.h"
#include <TFile.h>
#include <TDirectory.h>
#include <TH1D.h>
#include <TMatrixD.h>

#include <string>
#include <vector>


using namespace std;

class CTSweights
{
	private:
		bool m_av = false;
		//TMatrixD m_fac;
		//vector<double> m_res;
		vector<vector<double> > m_weights;
		int bin = 0;
		TFile* m_ctsfile = nullptr;
		TH1D* m_hcts = nullptr;
		//map<string, map<Bin, vector<TH1D*> > > m_hists;

	public:
	//	Add1DHist(const string& name, const vector<double>& binning)
	//	{
	//		for(size_t b = 0 ; b  < binning.size()-1 ; ++b)
	//		{
	//			Bin bin(binning[b], binning[b+1]);
	//			for(size_t h = 0 ; h <= m_res.size() ; ++h)
	//			{
	//				string hname = name+"_"+to_string(b)+"_"+to_string(h);
	//				m_hists[name][bin].push_back(TH1D(hname.c_str(), hname.c_str(), m_res.size(), -1, 1));
	//			}
	//		}
	//	}

		void init(string filename)
		{
			TDirectory* dir = gDirectory;
			m_ctsfile = TFile::Open(filename.c_str());
			m_hcts = dynamic_cast<TH1D*>(m_ctsfile->Get("cts_truth"));
			dir->cd();
			int n = m_hcts->GetNbinsX();
			TMatrixD m(n,n);
			TMatrixD vcts(n,1);
			TMatrixD m_fac(n,1);
			for(int r = 0 ; r < n ; ++r)
			{
				vcts(r,0) = m_hcts->GetBinContent(r+1);	
				m(r,0) = 1;	
				m(r,1) = m_hcts->GetBinCenter(r+1);	
			}

			for(int c = 2 ; c < n ; ++c)
			{
				for(int r = 0 ; r < n ; ++r)
				{
					m(r,c) = ((2*c-1)*m_hcts->GetBinCenter(r+1)*m(r,c-1) - (c-1)*m(r,c-2))/c;	
				}
			}
			m.Print();
			TMatrixD M(m);
			vcts.Print();
			m.Invert();
			m_fac.Mult(m, vcts);

			m_weights.resize(n);
			for(int r = 0 ; r < n ; ++r)
			{
				m_weights[r].resize(n);
				double sum = 0.;	
				for(int c = 0 ; c < n ; ++c)
				{
					//m_weights[r][c] = m_fac(c,0)*M(r,c);
					//m_weights[r][c] = M(r,c)/m_hcts->GetBinContent(r+1)*m_hcts->Integral()/n;
					m_weights[r][c] = M(r,c)/m_hcts->GetBinContent(r+1);
					sum += m_weights[r][c];
				}
				//for(int c = 0 ; c < n ; ++c)
				//{
				//	m_weights[r][c] /= sum;
				//}
			}


		}
		void reset() {m_av = false;}

		void cal(double cts)
		{
			m_av = true;
			bin = m_hcts->FindFixBin(cts)-1;
		}
		const vector<double>& weights(bool& ctssignal) {ctssignal = m_av; return m_weights[bin];}

};
#endif
