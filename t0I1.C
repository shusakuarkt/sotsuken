//#include <bits/stdc++.h>
//using namespace std;
class base{
  //  double t=0;//time

  /////////////////////////////////////////////////////
public:
  
  //  double A,B,a,b,c,C,Cs,r0,Rs,R,R0,RI,V0,n;
  double   V0=6.0e+3;//voltage
  double   R=2e+7;
  double   r0=20;
  double   Rs=1e+6;
  double   C=4e-9;
  double   RI=2e+8;
  double   R0=r0+RI;
  double   n=1;//number of layer
  double   alx=200.*1e-3;
  double   aly=200.*1e-3;
  double   alxt=150.*1e-3;
  double   alyt=150.*1e-3;
  double   acx=1.5*1e-3;
  double   acy=16.5*1e-3;
  double   acz=0.5*1e-3;
  double   eacrm=2.7;
  double   eacrM=4.5;
  double   eair=1.000586;
  double   egasAr=1.00517;
  double   egasHe=1.0007;
  double   evacu=8.85e-12;
  double acS=acx*acy*4;
  double Cm=(eair*evacu*(alx*alx-alxt*alxt-acS)/acz)+(eacrm*evacu*(acS)/acz)+(egasHe*evacu*(alxt*alxt)/acz);
  double CM=(eair*evacu*(alx*alx-alxt*alxt-acS)/acz)+(eacrM*evacu*(acS)/acz)+(egasHe*evacu*(alxt*alxt)/acz);
  double   Cs=(Cm+CM)/2;


  ////////////////////////////////////////////////////
  
  double   A=Rs*(1/R+1/r0)*(1/n+Cs/C);
  double   B=Rs*(1/R+1/r0)*(1/n-Cs/C);

  double   a=(-(1+A)+sqrt(1+A*A+2*B))/(2*Rs*Cs);
  double   b=(-(1+A)-sqrt(1+A*A+2*B))/(2*Rs*Cs);
  double   c=1/(Rs*Cs);

  double I1(double tt);
  double I2(double tt);
  double V1(double i1);
  double V2(double i1,double i2);
  double Geta();
  double Getb();
  double Getcoeffa();
  double Getcoeffb();
  void SetV0(double v0);
  void SetR(double r);
  void Setr0(double R0);
  void SetRs(double rs);
  void SetC(double c);
  void SetCs(double cs);
  void SetRI(double ri);
  void Setn(double N);
  double GetV0();
  double GetR();
  double Getr0();
  double GetRs();
  double GetC();
  double GetCs();
  double GetRI();
  double Getn();
  void SetCm(double cm);
  void SetCM(double cM);  
  void Setalx(double Alx);
  void Setaly(double Aly);
  void Setalxt(double Alxt);
  void Setalyt(double Alyt);
  void Setacx(double Acx);
  void Setacy(double Acy);
  void Setacz(double Acz);
  void Seteacrm(double Eacrm);
  void SeteacrM(double EacrM);
  void Seteair(double Eair);
  void SetegasAr(double EgasAr);
  void SetegasHe(double EgasHe);
  void Setevacu(double Evacu);
  double GetCm();
  double GetCM();  
  double Getalx();
  double Getaly();
  double Getalxt();
  double Getalyt();
  double Getacx();
  double Getacy();
  double Getacz();
  double Geteacrm();
  double GeteacrM();
  double Geteair();
  double GetegasAr();
  double GetegasHe();
  double Getevacu();




  void Reset();//reset all
};  
double base:: I1(double tt){ return (((a+c)*exp(a*tt)/(a-b))-((b+c)*exp(b*tt)/(a-b)))*RI*V0/((R+R0)*r0);
};
double base:: I2(double tt) {return (-1)*(((Cs/C)+(R*r0*Cs*a)/(R+r0))*((a+c)*exp(a*tt)/(a-b))-(((Cs/C)+(R*r0*Cs*b)/(R+r0))*(b+c)*exp(b*tt)/(a-b)))*RI*V0/((R+R0)*r0);
};
double base:: V1(double i1) {
    return r0*(V0+R*i1)/(R+R0);
};
double base:: V2(double i1,double i2) {
    return Rs*(i1/n-i2);
};
void base:: SetV0(double v0){
  V0=v0;
};
void base:: SetR(double r){
  R=r;
};
void base:: Setr0(double R0){
  r0=R0;
};
void base:: SetRs(double rs){
  Rs=rs;
};
void base:: SetC(double c){
  C=c;
};
void base:: SetCs(double cs){
    Cs=cs;
};
void base:: SetRI(double ri){
  RI=ri;
};
void base:: Setn(double N){
   n=N;
};
double base:: GetV0(){
  return  V0;
};
double base:: GetR(){
  return R;
};
double base:: Getr0(){
  return r0;
};
double base:: GetRs(){
  return Rs;
};
double base:: GetC(){
  return C;
};
double base:: GetCs(){
  return Cs;
};
double base:: GetRI(){
  return RI;
};
double base:: Getn(){
  return n;
};
double base::Geta(){
  return a;
};
double base::Getb(){
  return b;
};
double base::Getcoeffa(){
  return (Cs/C)+(R*r0*Cs*a)/(R+r0);
};
double base::Getcoeffb(){
  return (Cs/C)+(R*r0*Cs*b)/(R+r0);
};
void base::SetCm(double cm) {
  Cm=cm;
};
void base::SetCM(double cM){
  CM=cM;
};
void base::Setalx(double Alx){
  alx=Alx;
};
void base::Setaly(double Aly){
  aly=Aly;
};
void base::Setalxt(double Alxt){
  alxt=Alxt;
};
void base::Setalyt(double Alyt){
  alyt=Alyt;
};
void base::Setacx(double Acx){
  acx=Acx;
};
void base::Setacy(double Acy){
  acy=Acy;
};
void base::Setacz(double Acz){
  acz=Acz;
};
void base::Seteacrm(double Eacrm){
  eacrm=Eacrm;
};
void base::SeteacrM(double EacrM){
  eacrM=EacrM;
};
void base::Seteair(double Eair){
  eair=Eair;
};
void base::SetegasAr(double EgasAr){
  egasAr=EgasAr;
};
void base::SetegasHe(double EgasHe){
  egasHe=EgasHe;
};
void base::Setevacu(double Evacu){
  evacu=Evacu;
};
double base::GetCm(){
  return Cm;
};
double base::GetCM(){
  return CM;
};  
double base::Getalx(){
  return alx;
};
double base::Getaly(){
  return aly;
};
double base::Getalxt(){
  return alxt;
};
double base::Getalyt(){
  return alyt;
};
double base::Getacx(){
  return acx;
};
double base::Getacy(){
  return acy;
};
double base::Getacz(){
  return acz;
};
double base::Geteacrm(){
  return eacrm;
};
double base::GeteacrM(){
  return eacrM;
};
double base::Geteair(){
  return eair;
};
double base::GetegasAr(){
  return egasAr;
};
double base::GetegasHe(){
  return egasHe;
};
double base::Getevacu(){
  return evacu;
};


void base::Reset(){
     V0=6.0e+3;//voltage
     R=2e+7;
     r0=20;
     Rs=1e+6;
     C=4e-9;
     RI=2e+8;
     R0=r0+RI;
     n=1;//number of layer
     alx=200.*1e-3;
     aly=200.*1e-3;
     alxt=150.*1e-3;
     alyt=150.*1e-3;
     acx=1.5*1e-3;
     acy=16.5*1e-3;
     acz=0.5*1e-3;
     eacrm=2.7;
     eacrM=4.5;
     eair=1.000586;
     egasAr=1.00517;
     egasHe=1.0007;
     evacu=8.85e-12;
     acS=acx*acy*4;
     Cm=(eair*evacu*(alx*alx-alxt*alxt-acS)/acz)+(eacrm*evacu*(acS)/acz)+(egasHe*evacu*(alxt*alxt)/acz);
     CM=(eair*evacu*(alx*alx-alxt*alxt-acS)/acz)+(eacrM*evacu*(acS)/acz)+(egasHe*evacu*(alxt*alxt)/acz);
     Cs=(Cm+CM)/2;

};

    // t+=1e-9;
    // v1=V1(I1(ttt));
    // i1=I1(ttt);
    // v2=-V2(I1(ttt),I2(ttt));
    // i2=-I2(ttt);




  ////////////////////////////////////////////////////

void t0I1(){
  vector<string> name={"R","r0","Rs","C","RI","n"};
  base *base1=new base();
  TCanvas* c1 = new TCanvas();
  TCanvas* c2 = new TCanvas();
  TGraph* voltage1 = new TGraph();
  TGraph* current1 = new TGraph();
  TGraph* voltage2 = new TGraph();
  TGraph* current2 = new TGraph();
  double v1,v2,i1,i2;
  double t=0;
  string v0,xaxis;

  //  c1->Divide(5,1);

  int k=0,l=0,m=0;//"R","r0","Rs","C","RI","n"
  while(1){
    t=0;
    //    int o=0;
    //    c1->cd(j+1);
    //    R=2e+7 r0=20 Rs=1e+6 C=4e-9 RI=2e+8 n=1
    double v0v;
    for(int i=0;i<1000;i++){
    if(l==0){
      base1->SetR((2e+7)+(i)*1e+6);
      v0v=base1->GetR();
      v0="R(Mohm)Hikaku";
      xaxis="Mohm";
    }
    else if(l==1){
      base1->Setr0(20+(i)*1);
      v0v=base1->Getr0();
      v0="r0(ohm)Hikaku";
      xaxis="ohm";
    }
    else if(l==2){
      base1->SetRs((1e+6)+(i)*1e+5);
      v0v=base1->GetRs();
      //      if(i%2==0){
	v0="Rs(Mohm)Hikaku";
	// }
	// else{
	//	v0="Rs="+to_string((int)(v0v/1e+6))+".5Mohm";
	//  }
      v0v=(v0v/1e+6);
      xaxis="Mohm";
    }
    else if(l==3){
      base1->SetC(4e-9+(i)*1e-10);
      v0v=base1->GetC();
      if(1){
	v0="C(nF)Hikaku";
      }
      else{
	v0="C="+to_string((int)(v0v*1e+9))+".5nF";
      }
      v0v=(v0v*1e+9);
      xaxis="nF";
    }
    else if(l==4){
      base1->SetRI(2e+8+(i)*1e+7);
      v0v=base1->GetRI();
      v0="RI(Mohm)Hikaku";
      v0v=(v0v/1e+6);
      xaxis="Mohm";
    }
    else if(l==5){
      base1->Setn(1+(i)*0.1);
      v0v=base1->Getn();
      v0="n(layer)Hikaku";
      if(i==4){
	m=1;
      }
      //      v0v=v0v;
      xaxis="layer";
    }
    i1=base1->I1(t);
    i2=base1->I2(t);
    v1=base1->V1(i1);
    v2=base1->V2(i1,i2);
    voltage1->SetPoint(i,v0v,v1);
    current1->SetPoint(i,v0v,i1);
    voltage2->SetPoint(i,v0v,v2);
    current2->SetPoint(i,v0v,i2);
    }


  /////////////////////////////////////////////////////

    string plotname="CapacitorCurrent"+v0;
  //プロットのための整形処理
  current1->SetMarkerStyle(20);
  current1->SetMarkerColor(kRed);
  current1->SetMarkerSize(0.5);
  current1->GetXaxis()->SetTitle(xaxis.c_str());
  current1->GetYaxis()->SetTitle("current [A]");
  current1->GetYaxis()->SetTitleOffset(1.3);
  current1->SetTitle(plotname.c_str());
  // current2->SetMarkerStyle(20);
  // current2->SetMarkerColor(kBlue);
  // current2->SetMarkerSize(0.3);
  
  current1->Draw("AP");
  //  current2->Draw("P");

  //凡例の表示
  TLegend* tl=new TLegend(0.7,0.4,0.9,0.5);
  tl->AddEntry(current1,"capacitor","p");
  // tl->AddEntry(current2,"chamber","p");
  tl->SetTextSize(0.03);//プロットのための整形処理
  tl->Draw();
  string printname="CapacitorCurrent"+v0+".png";

  gPad->Print(printname.c_str());
  //  if(k==4){
    base1->Reset();
    // k=-1;
    // }
  if(m==1){
    break;
  }
  //  k++;
  l++;

  }
  
  // for(int i=0; i<1000; i++){
  //   t+=1e-10;
  //   i1=base1->I1(t);
  //   i2=base1->I2(t);
  //   v1=base1->V1(i1);
  //   v2=base1->V2(i1,i2);
  //   voltage1->SetPoint(i,t*1e+9,v1);
  //   current1->SetPoint(i,t*1e+9,i1);
  //   voltage2->SetPoint(i,t*1e+9,v2);
  //   current2->SetPoint(i,t*1e+9,i2);
    
  //   //    cout<<i1<<" "<<i2<<endl;
  // };
  // cout<<base1->Geta()<<" "<<base1->Getb()<<endl;
  // cout<<base1->Getcoeffa()<<" "<<base1->Getcoeffb()<<endl;
  /////////////////////////////////////////////////////


  // //プロットのための整形処理
  // voltage2->SetMarkerStyle(20);
  // voltage2->SetMarkerColor(kRed);
  // voltage2->SetMarkerSize(0.5);
  // voltage2->GetXaxis()->SetTitle("time[ns]");
  // voltage2->GetYaxis()->SetTitle("Voltage [V]");
  // voltage2->GetYaxis()->SetTitleOffset(1.3);
  // voltage2->SetTitle("voltage");
  // voltage1->SetMarkerStyle(20);
  // voltage1->SetMarkerColor(kBlue);
  // voltage1->SetMarkerSize(0.5);
  
  // voltage2->Draw("AP");
  // voltage1->Draw("P");

  // //凡例の表示
  // TLegend* tl=new TLegend(0.5,0.2,0.89,0.3);
  // tl->AddEntry(voltage1,"capaciter","p");
  // tl->AddEntry(voltage2,"chamber","p");
  // tl->SetTextSize(0.03);//プロットのための整形処理
  // tl->Draw();


  // gPad->Print("voltage_comparison.png");

  ///////////////////////////////////////////////////////////////////
  
  //プロットのための整形処理
  // current1->SetMarkerStyle(20);
  // current1->SetMarkerColor(kRed);
  // current1->SetMarkerSize(0.5);
  // current1->GetXaxis()->SetTitle("time[ns]");
  // current1->GetYaxis()->SetTitle("Current [A]");
  // current1->GetYaxis()->SetTitleOffset(1.3);
  // current1->SetTitle("current_20Mohm");
  // current2->SetMarkerStyle(20);
  // current2->SetMarkerColor(kBlue);
  // current2->SetMarkerSize(0.5);
  
  // current1->Draw("AP");
  // current2->Draw("P");

  // //凡例の表示
  // TLegend* tl2=new TLegend(0.5,0.2,0.89,0.3);
  // tl2->AddEntry(current1,"capaciter","p");
  // tl2->AddEntry(current2,"chamber","p");
  // tl2->SetTextSize(0.03);//プロットのための整形処理
  // tl2->Draw();

  // // current1->Draw("AP");
  // // current2->Draw("same");
  // gPad->Print("current_20Mohm.png");

  //  gPad->SetLogz();



  
  ////////////////////////////////////////////////////
  //////////////////////////////////////////////////////

  
 
  
}
