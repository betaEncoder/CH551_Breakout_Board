# CH551_Breakout_Board

## これは何？
WCH社製のUSBペリフェラル付きのマイコンであるCH551Gを搭載したブレイクアウトボードです．

WCHとは？CH551とは？については拙著のアドベントカレンダー記事の [こちら](https://tech-blog.cerevo.com/archives/6068/) を御覧ください．
また，デバイスの詳細についてはメーカの [製品ページ](http://www.wch.cn/products/CH551.html) を御覧ください．

デバイスの [データシート](http://www.wch.cn/download/CH552DS1_PDF.html) (CH551/552共通)は中国語ですが，雰囲気で読めます．

若しくは，有志が [和訳データシート](https://t.co/2vzyWYPxOI) を公開してくれています．参考にさせていただきましょう．

## 回路図
[PDF](CH551_BB_sch.pdf)

## Pin map
![Pin map](img/pin_map.png)

## 開発環境の導入

### インストール
以下のツールが必要です．DLしてインストールしてください．
- [uVision C51](https://www.keil.com/download/product/) (試用版でもビルド可能ですがコードサイズ制限があります)
  - CH551は8051コアなのでMDK-Armではなく，8051用のC51をインストールしてください．
- [WCHISPTool](http://wch.cn/download/WCHISPTool_Setup_exe.html) (チップにhexを書き込むためのツールです)

### チップ情報の組み込み
uVisionはデフォルトではWCHのチップ情報を持っていません．無くてもBuildして書き込み，動作できますが，メーカが用意してくれているので活用しましょう．

WCHISPToolを実行し，ツールバーから Function-Add WCH MCU Database to Keil をクリックします．
これによってuVisionにWCHのチップ情報が組み込まれたり，組み込まれなかったりします．
私の環境ではPCによって上手くいったり，いかなかったりしました．
![Add Database](img/WCHISPTool.png)

### SDKをダウンロード
あああ

### uVisionでプロジェクトを設定&Build
いいい

### 書き込み
ううう