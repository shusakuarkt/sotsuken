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
  double   n=1;//number of layer
  double   alx=200.*1e-3;
  double   aly=200.*1e-3;
  double   alxt=150.*1e-3;
  double   alyt=150.*1e-3;
  double   acx=15*1e-3;
  double   acy=165*1e-3;
  double   acz=5*1e-3;
  double   eacrm=2.7;
  double   eacrM=4.5;
  double   eair=1.000586;
  double   egasAr=1.00517;
  double   egasHe=1.0007;
  double   evacu=8.85e-12;
  double   R0=r0+RI;
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
  double GetA();
  double GetB();
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

  double Geti2migi();
  void update();

  void Reset();//reset all
};
void base::update(){
  R0=r0+RI;
  acS=acx*acy*4;
  Cm=(eair*evacu*(alx*alx-alxt*alxt-acS)/acz)+(eacrm*evacu*(acS)/acz)+(egasHe*evacu*(alxt*alxt)/acz);
  CM=(eair*evacu*(alx*alx-alxt*alxt-acS)/acz)+(eacrM*evacu*(acS)/acz)+(egasHe*evacu*(alxt*alxt)/acz);
  Cs=(Cm+CM)/2;
  A=Rs*(1/R+1/r0)*(1/n+Cs/C);
  B=Rs*(1/R+1/r0)*(1/n-Cs/C);
  a=(-(1+A)+sqrt(1+A*A+2*B))/(2*Rs*Cs);
  b=(-(1+A)-sqrt(1+A*A+2*B))/(2*Rs*Cs);
  c=1/(Rs*Cs);
}
double base:: I1(double tt){ return (((a+c)*exp(a*tt)/(a-b))-((b+c)*exp(b*tt)/(a-b)))*RI*V0/((R+R0)*r0);
};
double base:: I2(double tt) {return (-1)*(((Cs/C)+(R*r0*Cs*a)/(R+r0))*((a+c)*exp(a*tt)/(a-b))-(((Cs/C)+(R*r0*Cs*b)/(R+r0))*(b+c)*exp(b*tt)/(a-b)))*RI*V0/((R+R0)*r0);
};
double base::GetA(){
  return A;
};
double base::GetB(){
  return B;
};
double base::Geti2migi(){
  return (Cs/C)+(R*r0*Cs*b)/(R+r0);
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
