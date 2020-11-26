#include "base.h"

void buhin(){
  base *base1=new base();
  TCanvas* c1 = new TCanvas();
  TGraph* voltage1 = new TGraph();
  TGraph* current1 = new TGraph();
  TGraph* voltage2 = new TGraph();
  TGraph* current2 = new TGraph();
  double v1,v2,i1,i2;
  double t=0;
  int y=0;
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
  i1=base1->I1(t);
  i2=base1->I2(t);
  v1=base1->V1(i1);
  v2=base1->V2(i1,i2);
  cout<<"I1's highest current is"<<i1<<endl;

  cout<<"IGBTにかかる最高電圧は"<<base1->GetRI()*base1->GetV0()/(base1->GetR()+base1->Getr0()+base1->GetRI())<<endl;
  i1=base1->I1(base1->GetV2highesttime());
  i2=base1->I2(base1->GetV2highesttime());
  v1=base1->V1(i1);
  v2=base1->V2(i1,i2);

    cout<<"V2's highest voltage is"<<v2<<endl;
  
    double z=0,p=0;
  for(int i=0; i<10000000; i++){
    i1=base1->I1(t);
    i2=base1->I2(t);
    v1=base1->V1(i1);
    v2=base1->V2(i1,i2);
    voltage1->SetPoint(i,t*1e+9,v1);
    current1->SetPoint(i,t*1e+9,i1);
    voltage2->SetPoint(i,t*1e+9,v2);
    current2->SetPoint(i,t*1e+9,i2);
    if(v2>3000&&p==0){
      p=t;
      cout<<"初めて3kVを超えるのは"<<p*1e+6<<"micro seconds"<<endl;
    }
    
    if(v2>4000&&z==0){
      z=t;
      cout<<"初めて4kVを超えるのは"<<z*1e+6<<"micro seconds"<<endl;
    }
    if(v2<4000&&z!=0){
      cout<<"4kVを超えているのは"<<(t-z)*1e+6<<"micro seconds"<<endl;
      z=0;
      y=1;
    }
    if(v2<3000&&p!=0){
      cout<<"3kVを超えているのは"<<(t-p)*1e+6<<"micro seconds"<<endl;
      p=0;
      y=1;
    }

    if(v2<1&&y==1){
      cout<<"1Vより小さくなるのは"<<t<<"seconds"<<endl;
      y=0;
    }
    t+=1e-10;
  };


  /////////////////////////////////////////////////////


  //プロットのための整形処理
  voltage2->SetMarkerStyle(20);
  voltage2->SetMarkerColor(kRed);
  voltage2->SetMarkerSize(0.5);
  voltage2->GetXaxis()->SetTitle("time[ns]");
  voltage2->GetYaxis()->SetTitle("Voltage [V]");
  voltage2->GetYaxis()->SetTitleOffset(1.3);
  voltage2->SetTitle("voltage");

  voltage2->Draw("AP");


  //凡例の表示
  TLegend* tl=new TLegend(0.5,0.2,0.89,0.3);
  tl->AddEntry(voltage2,"chamber","p");
  tl->SetTextSize(0.03);//プロットのための整形処理
  tl->Draw();


  gPad->Print("voltagetestkouhani.png");



  
  ////////////////////////////////////////////////////

  
 
  
}
