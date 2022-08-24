
ll A[N];
//树状数组维护前缀和。只维护C,不会使用A。
ll C[N];
int lowbit(int x){ // 返回最低位的1
  return -x&x; // 原理：-x是取x的补码，即反码+1。二进制数加一时最低位的0成为1，更低的1都成为0。因此-x&x，最低位的1（反码中最低位的0）会保留下来，其他都会变成0，这样就得到了x的最低位的1
}
void update(int i,int x,int n){
  for(;i<=n;i+=lowbit(i))
    C[i]+=x;
}
ll query(int i){
  ll ans = 0;
  for(;i;i-=lowbit(i)) //每次处理一个长度为lowbit(i)的区间
    ans += C[i];
  return ans;
}

//树状数组维护区间最值，A[i]必须已经更新
ll C[N];
int lowbit(int x){ // 返回最低位的1
  return -x&x; // 原理：-x是取x的补码，即反码+1。二进制数加一时最低位的0成为1，更低的1都成为0。因此-x&x，最低位的1（反码中最低位的0）会保留下来，其他都会变成0，这样就得到了x的最低位的1
}
void update(int i,int n){
  for(;i<=n;i+=lowbit(i)){
    C[i] = A[i];
    for(int j=lowbit(i)>>1;j;j>>1) //枚举被管辖的数
      C[i] = max(C[i],C[i-j]);
  }
}
ll query(int l,int r){
  ll ans = 0;
  while(l<=r)
    if (r-lowbit(r)+1 >= l){ //保证C[r]代表的区间没有越界
      ans = max(ans,C[r]);
      r-=lowbit(r);
    }
    else{ // 否则只走一步
      ans = max(ans,A[r]);
      r--;
    }
  return ans;
}
