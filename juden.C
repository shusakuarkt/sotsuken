#include "basejuden.h"
void juden(){
  vector<string> name={"R","r0","Rs","C","RI","n"};
  base *base1=new base();
  double v1,v2,i1,i2;
  double t=0;
  string v0,xaxis;
  double v0v=0;
  double v3=0;
  int d=0;
  int k=0,l=0,m=0,y=0;//"R","r0","Rs","C","RI","n"
  while(1){
    TGraph* voltage1 = new TGraph();
    TGraph* current1 = new TGraph();
    TGraph* voltage2 = new TGraph();
    TGraph* current2 = new TGraph();
    base1->SetV0(4900);
    base1->SetR(1e+7);
    base1->Setr0(30);
    base1->SetRs(5e+4);
    base1->SetC(2e-9);
    base1->SetRI(1e+8);
    base1->Setn(2);
    base1->Setalx(200.*1e-3);
    base1->Setaly(200.*13-3);
    base1->Setalxt(150.*1e-3);
    base1->Setalyt(150.*1e-3);
    base1->Setacx(15.*1e-3);
    base1->Setacy(165.*1e-3);
    base1->Setacz(5.*1e-3);
    
    base1->update();

    TCanvas* c1 = new TCanvas();
    for(int z=0;z<70000;z++){
      base1->update();
      t=(double)z*1e-5;
      i1=base1->I1(t);
      i2=base1->I2(t);
      v1=base1->V1(i1);
      v2=base1->V2(i1,i2);
      voltage2->SetPoint(y,t*1e+3,v1);
	y++;
	if(v3<v1){
	  v3=v1;
	}
	else if(v1==v3&&m==0){
	cout<<"充電するまで"<<t*1e+3<<"ms"<<endl;
	m=1;
      }
    }



  /////////////////////////////////////////////////////

    string plotname="juden"+v0;
  //プロットのための整形処理
    voltage2->SetMarkerStyle(20);
    voltage2->SetMarkerColor(kRed);
    voltage2->SetMarkerSize(0.5);
    voltage2->GetXaxis()->SetTitle("time[ms]");
    voltage2->GetYaxis()->SetTitle("voltage[V]");
    voltage2->GetYaxis()->SetTitleOffset(1.3);
    voltage2->SetTitle(plotname.c_str());
  
    voltage2->Draw("AP");

    string printname="juden"+v0+".png";

    gPad->Print(printname.c_str());
    base1->Reset();
    //    if(m==1){
      break;
      // }
    l++;
    
  }
}
