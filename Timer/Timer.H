

 #define  T0_INT   1                                                        //T�жϿ���
//#define  T1_INT   1
// #define  T2_INT   1
// #define  T2_CAP   1

extern UINT8 FLAG; 
extern UINT16 Cap[8];

//CH554 Timer0ʱ��ѡ��   
//bTMR_CLKͬʱӰ��Timer0&1&2,ʹ��ʱҪע�� (����ʱʹ�ñ�׼ʱ��)            
#define mTimer0Clk12DivFsys( ) (T2MOD &= ~bT0_CLK)                          //��ʱ��,ʱ��=Fsys/12 T0��׼ʱ��
#define mTimer0ClkFsys( )      (T2MOD |= bTMR_CLK | bT0_CLK)                //��ʱ��,ʱ��=Fsys
#define mTimer0Clk4DivFsys( )  (T2MOD &= ~bTMR_CLK;T2MOD |=  bT0_CLK)       //��ʱ��,ʱ��=Fsys/4
#define mTimer0CountClk( )     (TMOD |= bT0_CT)                             //������,T0���ŵ��½�����Ч

//CH554 Timer0 ��ʼ(SS=1)/����(SS=0)
#define mTimer0RunCTL( SS )    (TR0 = SS ? START : STOP)


#define mTimer1Clk12DivFsys( ) (T2MOD &= ~bT1_CLK)                          //��ʱ��,ʱ��=Fsys/12  T1��׼ʱ��
#define mTimer1ClkFsys( )      (T2MOD |= bTMR_CLK | bT1_CLK)                //��ʱ��,ʱ��=Fsys
#define mTimer1Clk4DivFsys( )  (T2MOD &= ~bTMR_CLK;T2MOD |=  bT1_CLK)       //��ʱ��,ʱ��=Fsys/4
#define mTimer1CountClk( )     (TMOD |= bT1_CT)                             //������,T0���ŵ��½�����Ч

//CH554 Timer1 ��ʼ(SS=1)/����(SS=0)
#define mTimer1RunCTL( SS )    (TR1 = SS ? START : STOP)


#define mTimer2Clk12DivFsys( ) {T2MOD &= ~ bT2_CLK;C_T2 = 0;}      //��ʱ��,ʱ��=Fsys/12 T2��׼ʱ��
#define mTimer2ClkFsys( )      {T2MOD |= (bTMR_CLK | bT2_CLK);C_T2=0;}         //��ʱ��,ʱ��=Fsys
#define mTimer2Clk4DivFsys( )  {T2MOD &= ~bTMR_CLK;T2MOD |=  bT2_CLK;C_T2 = 0;}//��ʱ��,ʱ��=Fsys/4
#define mTimer2CountClk( )     {C_T2 = 1;}                                     //������,T2���ŵ��½�����Ч

//CH554 Timer2 ��ʼ(SS=1)/����(SS=0)
#define mTimer2RunCTL( SS )    {TR2 = SS ? START : STOP;}
#define mTimer2OutCTL( )       (T2MOD |= T2OE)                               //T2���  Ƶ��TF2/2   
#define CAP1Alter( )           (PIN_FUNC |= bT2_PIN_X;)                      //CAP1��P10 ӳ�䵽P14
#define CAP2Alter( )           (PIN_FUNC |= bT2EX_PIN_X;)                    //CAP2��P11 ӳ��RST

/*******************************************************************************
* Function Name  : mTimer_x_ModInit(UINT8 x ,UINT8 mode)
* Description    : CH554��ʱ������xģʽ����
* Input          : UINT8 mode,Timerģʽѡ��
                   0��ģʽ0��13λ��ʱ����TLn�ĸ�3λ��Ч
                   1��ģʽ1��16λ��ʱ��
                   2��ģʽ2��8λ�Զ���װ��ʱ��
                   3��ģʽ3������8λ��ʱ��  Timer0
                   3��ģʽ3��Timer1ֹͣ		
                   UINT8 x ��ʱ��  0 1 2
* Output         : None
* Return         : �ɹ�  SUCCESS
                   ʧ��  FAIL
*******************************************************************************/
UINT8 mTimer_x_ModInit(UINT8 x ,UINT8 mode);

/*******************************************************************************
* Function Name  : mTimer_x_SetData(UINT8 x,UINT16 dat)
* Description    : CH554Timer 
* Input          : UINT16 dat;��ʱ����ֵ
                   UINT8 x ��ʱ��  0 1 2
* Output         : None
* Return         : None
*******************************************************************************/
void mTimer_x_SetData(UINT8 x,UINT16 dat);

/*******************************************************************************
* Function Name  : CAP2Init(UINT8 mode)
* Description    : CH554��ʱ������2 T2EX���Ų�׽���ܳ�ʼ��
                   UINT8 mode,���ز�׽ģʽѡ��
                   0:T2ex���½��ص���һ���½���
                   1:T2ex�������֮��
                   3:T2ex�������ص���һ��������
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void CAP2Init(UINT8 mode);

/*******************************************************************************
* Function Name  : CAP1Init(UINT8 mode)
* Description    : CH554��ʱ������2 T2���Ų�׽���ܳ�ʼ��T2
                   UINT8 mode,���ز�׽ģʽѡ��
                   0:T2ex���½��ص���һ���½���
                   1:T2ex�������֮��
                   3:T2ex�������ص���һ��������
* Input          : None
* Output         : None
* Return         : None
*******************************************************************************/
void CAP1Init(UINT8 mode);