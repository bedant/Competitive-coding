#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
    int w,t;
    double px,py,pz,qx,qy,qz,dx,dy,dz,cx,cy,cz,r,tx,ty,tz,k,wx,wy,wz,quada,quadb,quadc,time,time1,time2,spha,sphb,sphc,sphtime,gx,gy,gz;
    cin>>t;
    for(w=0;w<t;w++)
    {
        cin>>px>>py>>pz>>qx>>qy>>qz>>dx>>dy>>dz>>cx>>cy>>cz>>r;
        tx=px-cx;ty=py-cy;tz=pz-cz;
        //cout<<"t "<<tx<<" "<<ty<<" "<<tz<<endl;
        k=tx*tx+ty*ty+tz*tz-r*r;
        //cout<<"k "<<k<<endl;
        wx=qx-px;wy=qy-py;wz=qz-pz;
        gx=qx-cx;gy=qy-cy;gz=qz-cz;
        spha= dx*dx + dy*dy + dz*dz;
        sphb=2 * (dx*gx+dy*gy+dz*gz);
        sphc= gx*gx+gy*gy+gz*gz - r*r;
        if(sphb*sphb-4*spha*sphc<0) sphtime=10000000001;
        else
        {
            sphtime= (-sphb-pow( sphb*sphb-4*spha*sphc , 0.5))/(2*spha);
        }
        if(sphtime<0) sphtime=10000000001;
        //cout<<"w "<<wx<<" "<<wy<<" "<<wz<<endl;
        quada=pow(tx*dx+ty*dy+tz*dz,2)-k*(dx*dx + dy*dy + dz*dz);
        //cout<<"a "<<quada<<endl;
        quadb= 2 * ( (tx*dx+ty*dy+tz*dz)*(tx*wx+ty*wy+tz*wz)-(dx*wx+dy*wy+dz*wz)*k );
        //cout<<"b "<<quadb<<endl;
        quadc=(tx*wx+ty*wy+tz*wz)*(tx*wx+ty*wy+tz*wz)-k*(wx*wx+wy*wy+wz*wz);
        //cout<<"c "<<quadc<<endl;
        if(quada)
        {
            time1=(-quadb + sqrt( quadb*quadb-4*quada*quadc ))/(2*quada);
            time2=(-quadb - sqrt( quadb*quadb-4*quada*quadc ))/(2*quada);
            if(time1<0 && time2>0) time=time2;
            if(time1<0 && time2<0) time=-1;
            if(time1>0 && time2<0) time=time1;
            if(time1>0 && time2>0)
            {
                if(time1>time2) time=time2;
                else time=time1;
            }
        }
        else
            time=-quadc/quadb;
        if(time<0) time=-1;
        if(time>sphtime || time>pow(10,9) ) time=-1;
        cout<<time<<"\n";
    }
}
