2次元レトロマップツール  by 山川機長

作者連絡先:     PEB01130@nifty.com
作者Webサイト:  http://www.ysflight.com
取り扱い種別:   フリー
ソースコード:   BSDライセンスでフリー
動作環境:       Windows, Mac, Linux (それぞれ対応パッケージをダウンロードしてください)





[注意 (重要!)]
このプログラムを使うと、レトロ(レトロじゃなくてもいいけど)二次元ゲームの原寸大マップを作製できる。例えば、自分で攻略サイトを立ち上げたいような場合に使える。とくに、マイナー過ぎてまだ誰も攻略サイト作ってないようなゲームの攻略サイトを作ると価値が高いかもしれない。

ただし、このプログラムのデータ形式 (.retromap形式)ファイルは、公開しない方がいい。もしも、自分で攻略サイトを立ち上げたいような場合は、完成品のマップをPNG形式の画像ファイルに出力したものをアップロードした方がいい。

このプログラムのデータ形式 (.retromap形式)は、スクリーンショットのPNGファイルの情報をそのまま記録する。トリムしても、あとからトリム範囲を広げられるように、元データを残したままにしている。

実はこのプログラム、ゲームのマップ作るだけかと思ったら、案外実用的な利用方法もあって、スクロールしないと全部が見えないWebサイトのスクリーンショットをつなげて一枚のPNGファイルにする、なんていうことができる。たまにPDFでセーブすると配置が崩れるとか、絵が消えるとか、そういう心配がない。

しかし、そのスクリーンショットには、他人に見てほしくない情報まで写りこんでいるかもしれない。企業秘密情報であったり、学生さんの成績情報とか漏洩するとリアルな人生がエンドになってしまうかもしれない。あるいは、他人に見てほしくないブックマークとか写りこんでしまって、突然、カミングアウトを余儀なくされたりするリスクがある。

それでなくてもスクリーンショットなので、このツールで作ったデータ(PNG形式でも)を公開するときは、細心の注意を払った方がいい。

このプログラムで作ったデータを公開した結果、大変なことになった、というような場合でも、作者は一切責任を負わないので、この点が了承できない場合は、使用を中止してください。





[はじめに]
このプログラムは、ザナドゥ・コンプリート・コレクションに収録されているの、リバイバル・ザナドゥ2を自力クリアする、という極めて限られた目的のために作った。

攻略サイトを見ればいいじゃないって? 自力で作るのがいいんだよ。

アイディアは非常に単純で、スクリーンショットのマップ部分を切り抜いて、それを貼り合わせて、原寸大マップを作るというもの。だから、リバイバル・ザナドゥ2に限らず、二次元マップのレトロゲームで、WindowsまたはMacで動くものであれば利用可能なはず。iOSのPhoto Streamを利用すれば、iOSデバイス上のスクリーンショットをPCまたはMacにPNG形式ファイルとして送ることができるので、iOS上のゲームにも対応可能。

このプログラムを開発した時点では、まだザナドゥ・コンプリート・コレクションは、手元になく、日本に帰省していた同僚に回収してきてもらうところだったため、二年前に買ってきて積んであったドラゴン・スレイヤー・クロニクル収録のPC88用ザナドゥで機能を検証した。自分としては欲しいレベルの機能を実現できて、大成功だったので、そこで止めても良かったのだが、ザナドゥをクリアしたもんだから、ザナドゥ・シナリオ2もムラムラとクリアしたくなってきてしまったため、結局シナリオ2もこのツールでマップを作りながらクリアしてしまった。

Falcomのザナドゥが登場した当時、僕は、なぜかファミコンは無いのにFM7を持っていた。その冬、お年玉をかき集めて、FM77AVを買った。ただ、2ドライブモデルを買えなかったもんだから、シングルドライブのモデルを買った。そのとき、頼み込んでザナドゥをおまけにつけてもらった。既に、電波新聞社発行の「山下章のチャレンジRPG」を持っていた(記憶が前後してるから多分合ってると思うんだけど)僕は、ほとんど解答集とも言える、その本の情報をフォローしてクリアしたと記憶している。

その後、ザナドゥ・シナリオ2が出る、と聞いたとき、なんとしてもやりたかった。が、果たしてFM7/77AV版が出るだろうかというのが最大の不安だった。なんせ、富士通のFMシリーズは、他機種に比べて非常に優れた特徴をいくつも持っているにも関わらず、なぜかマイナーという運命を背負っていた。その伝統はのちに続くFM-TOWNSにも脈々と受け継がれる伝統だった。当時、話題のゲームは、PC88、X1用はまず間違いなく出るものの、FM7/77AV版は出ないもんだから、何度涙を飲んだことか。

しかし、Falcomは、やってくれた。予定通り、FM77AV版、ザナドゥ・シナリオ2は発売された。前作は、攻略本を見て解いてしまったから、シナリオ2は自力クリアを目指そう。と、思った僕だったが、ザナドゥ・シナリオ2の壁は当時の僕には高すぎた。結構頑張って進めていたのだが、事故が発生。大体レベル6をなんとか歩き回れる程度になったとき、ふと、魔が差した。Black Onyxを使って次のレベルをちょっと見てみたい。レベル6の最上段に上り、そこから唯一のBlack Onyxを使ってレベル7へ。レベル7最上段には、見慣れないブロックがあった。中に入ると何かあるのだろうか？思わず、スペースキーを押すのを止められなかった、その時！「ぶーん」。ディスクの駆動音。それは、レベル11に続くCaveだった。非情にもオートセーブされてゆく。Black OnyxもFire Crystalも残ってない。レベル7の反対側の塔から脱出を試みるもボスキャラ(Buzzati)に阻まれて脱出できない。

ユーザーディスクのバックアップは取ってなかった。というか、当時フロッピーディスクは貴重品で、小遣いでそんなにたくさん買えるものではなく、そもそも、シナリオ2を買ったことによって財布が薄くなっていた僕には、バックアップ用の予備のディスクを買う金は残っていなかった。財力でも、ザナドゥ・シナリオ2に負けた。

完全に詰んだ。自力クリアの志はもろくも崩れ去ってしまったのであった。

バックアップさえあったなら。もともと、カセットテープにプログラムを保存していた時代、長い時間をかけて打ち込んだプログラムがテープが伸びて消滅という悲劇を何度も経験して、今では三重にバックアップが無いと不安で夜も眠れなくなってしまったが、このときの悲劇も、僕のバックアップ癖にいくばくかの貢献をしていると思う。

さすがに最初からやりなおす気力無くして、ディスクダンプを見てキャラクターデータを書き換えて続行して、レベル11は、コンプティークだったかな？のおまけのダンジョンマップを見ながらクリアしたと記憶している。ちなみに、FM-7版ザナドゥ、ザナドゥ・シナリオ2のデータディスクにはチェックサムがあった。が、データ部分をバイト単位で合計した値をどこかに書いてあるだけだったようで、例えば、Daggerを一本買ってセーブして、ディスクを書き換えて、Daggerを0本にしてDragon Slayer 1本に変化させることができた。

時は流れて、高校に入ってFM-TOWNSに乗り換えてからは、久しくFalcomのゲームからは遠ざかっていた。が、1998年にピッツバーグに引っ越していた僕は、Windows用にリバイバル・ザナドゥなる復刻版が出たことを知る。思わず、海外発送で買っちゃった。買ったのは、確か博士候補試験終わってからだったと思うから、多分1999年の後半。方眼紙のノートを買ってきて、タワーマップを書きつつ、多分二周はしたと思う。何がうれしかったって、BGMのWAVが入ってたから、しばらくプログラミング中のBGMに使った。今でもたまに聞くし。ちなみに、リバイバル・ザナドゥは、Windows 10ではインストールできるものの、そのままではセーブができない。Windows XP互換モードで起動するとセーブはできるようになるものの、しばらく使っていると「リソースが足りない」と言って落ちる。どうやら現実的にはプレイ不能のようだ。

そんなザナドゥにどっぷりはまった当時ゲーム少年、現在ゲーム中年の僕は、一昨年、帰省したとき、ソフマップの中古屋でドラゴン・スレイヤー・クロニクルを見つける。なんか、ガラスのショーケースに入ってて、プレミアム扱いだった。最初は、いや、買ってはいかん、そんな無駄遣いはいかん。と、思ったのだが、東京滞在の最終日、ここで買わんでどうする、と、気が変わって大人買い。ただ、買ったまま、ピッツバーグに持って帰ってきて、一年ばかり本棚に積んであった。

アメリカなんかに住んでるもんだから、いまいち日本国内の情報が遅い僕は、その年の12月に、ザナドゥ・コンプリート・コレクションなるものが発売されたことを、その一年後まで知らなかった。見つけたのは、本当に偶然、11月中に、なんかゲームでも買おうか、と、Amazon.co.jpを物色している途中見つけたと記憶している。ザナドゥ・コンプリート・コレクション、なんとしても欲しい内容があった。それは、リバイバル・ザナドゥ2。初代ザナドゥのシステムで、シナリオ2ともマップが違うらしい。なんとしても、やってみたかったのだが、Windows用に復刻してくれないから、涙を飲んでいた。しかし、そのリバイバル2が収録されているらしい。

なんとしても欲しかったのだが、情報が遅かった影響で既に予約はとっくに終わっていて、転売品を高値で買うしかできなかったが、そんなことは問題ではない。(いや、でも、できれば復刻版を数量限定とか予約限定とかしないでくれると海外に住んでる者としてはありがたいんだけど)。Amazon.co.jpで買っちゃった。そして、同僚に回収してきてもらう。

が、自力クリアするためには、マップを書かなくてはならない。そのためには、スクリーンショットをトリムして貼り合わせればいい、というわけで、できたのがこのツール。

なお、ザナドゥ・リバイバル2は、その後、このマップツールを使って、無事クリア。キング・ドラゴンはゴジラみたいな格好に変化していた。その後、友達に勧められるがままに、iOS用クロノトリガーを始めて、これもこのツールを使ってクリアして、iOS用の2次元ゲームにも対応できることを確認した。マップを書きながら進むから、道に迷うことがほとんどなくて、結果的に短時間でクリアできたと思う。ただ、iOS用で悪評が高い「死の山」だけは、友達に勧められるままに、攻略情報を見たけど。

ひょっとしたら、こういうツールって、すでに誰か別の人が作ったのがあるかもね。でも、僕っていちいちサーチするのが面倒なんだよね。まあ、こんなプログラムがひとつぐらい増えたっていいじゃないの。




[効能]
2次元ゲームのスクリーンショットから原寸大マップ作成。
PDFにプリントすると崩れてしまうWebサイトを、8割ぐらいずつスクロールしながらスクリーンショットを撮ってつなぎ合わせて一枚の巨大なビットマップにする。
Google Mapとかのスクリーンショットを撮りたいが、入れたい範囲をすべてカバーするまで引くと肝心の地名が消えてしまうような場合、ズームした状態でちょっとずつずらしながらスクリーンショットを撮ってつなぎあわせて一枚のビットマップにする。




[インストール]
このファイルを適当な場所に展開するだけです。アンインストール時はファイルを削除してください。




[起動方法]
Windows用    bin/2DRetroMapTool.exe をダブルクリック
macOS用      bin/2DRetroMapTool.app をダブルクリック
Linux用      bin/2DRetroMapTool.app/Contents/Resources/2DRetroMapTool を起動




[初回起動時にすること]
このプログラムでできることは、手間をかければ普通のペイントツールでもできる。新しいスクリーンショットを開いて、それを巨大ビットマップに次々に貼り付けて行けばいいだけ。しかし、普通のペイントツールでそれを実行しようとすると、新しいスクリーンショットをファイルセレクタで読み込んで、トリムするだけでも手間がかかって、やる気をくじかれてしまう。このツールが違うのは、ボタン一発で新しいスクリーンショットを読み込むことができて、それをマウスなりタッチなりでずるずると移動して張り合わせることができるという点。逆に、ボタン一発で新しいスクリーンショットを読み込むのでなければ、価値が半減すると言っていい。

デフォルトでは、~/Dropbox/Screenshots, ~/OneDrive/Pictures/Screenshots, ~/Desktop がスクリーンショット保存ディレクトリとして設定されていまる。Windowsでは、あらかじめ、このどちらかにスクリーンショットが保存されるようにシステムの設定を変更しておく必要がある。

もしも、このデフォルトの場所以外にスクリーンショットが発生するようであれば、[設定]->[設定]を選んで、場所を指定する必要がある。例えば、ドラゴンスレイヤー・クロニクルとか、ザナドゥ・コンプリート・コレクションのような、エミュレータベースのプログラムの場合、ウィンドウのスクリーンショットだと拡大がかかっている場合があって、ピクセル単位で微妙に色が違うことがある。そういう場合は、エミュレータのスクリーンショット機能を使う方が良くて、その機能を使って作ったビットマップを貼り合わせるのであれば、エミュレータが出力するスクリーンショットディレクトリを、このプログラムにも登録しておく必要がある。

また、問題は、iOS。iOSで、Photo Streamを使ってiCloud経由でスクリーンショットを同期すると、たとえば、iPhone5Sのスクリーンショットは、

    ~/Pictures/fromIPhone5S.photoslibrary/Masters

このディレクトリの、サブディレクトリのサブディレクトリ内に発生する。(ひとつのアカウントにふたつ以上の同じ機種があったらどうなるんだろう？)。

Photo Streamのスクリーンショットをボタン一発で読み込むように設定するには、[設定]→[設定]を選んで、使う機種用のMastersディレクトリをスクリーンショットフォルダに追加して、右の[Sub-Folder]をチェックする。Photo Streamだと、ときどき長いことシンクロナイズされなくて、スクリーンショットがPCに入ってこないことがあるけど、そこは忍耐力で我慢する。




[基本操作]
通常モード:

    スクロール:    Shift+左ボタンドラッグ、または、二本指タッチ(タッチパネルのみ)
    ボックス選択:  左ボタンを押して、領域を選んでボタンを放す。
    単一選択:      左ボタンで選びたいものをクリック。
    選択追加/解除: Control+左ボタンクリック
    削除:          Deleteキー
    移動:          選択したものの上で左ボタンをクリックしてドラッグ。




[コントロールダイアログの操作]
上段左:
    フィールドの選択。
矢印:
    画面のスクロール
画像を追加:
    ファイルダイアログで選んで画像を追加。
違いをハイライト:
    チェックしておくと、選択した画像を移動するとき他の画像と重なる部分の違いをハイライト。複数選択時は最初の数枚のみ。
Threshol:
    違いをハイライトするとき、どのぐらい明るさが違うピクセルを違うと認識するかの閾値。
新しいスクリーンショットを追加: 
    あらかじめ登録したスクリーンショットディレクトリに新たに発生したスクリーンショットを一枚追加。
コメントを追加:
    テキストコメントを追加。なお、複数行にするときは \n を入れると改行できる。
位置微調整:
    大雑把に位置あわせした後、最後の数ピクセルを、エラーが最小になるように微調整する。



[フィールドとワールドについて]
ゲームには、大概ステージがある。ひとつのステージ内のマップは連続しているが、違うステージに移動するとき、マップが切り替わったりする。このプログラムでは、ひとつのステージを「フィールド」という単位で管理する。

また、このフィールドを集めたもの、ゲーム全体を「ワールド」と呼ぶ。ひとつのデータファイルがひとつのワールドに対応する。ステージを変えるたびに、新しいデータファイルに切り替える必要は無い。(半面、メモリは食うけど)

それぞれのフィールド上には、スクリーンショットとマークアップを貼り付けることができる。スクリーンショットは、そのままゲームのスクリーンショット。マークアップには二種類あって、線(矢印可)と、テキストを貼り付けることができる。マップを作っている途中、手に入るアイテムとか、あるいは、ワープがあるとかいう場合、マークアップを使ってメモを書き込むことができる。

スクリーンショットを追加するには、基本的にゲーム上でスクリーンショットを撮って、メインダイアログの「新しいスクリーンショットを追加」ボタンをクリックする。追加したスクリーンショットはスクリーンショット上でマウス左ボタンを押してドラッグすることで移動できる。あるいは、選択状態で矢印キーを押しても移動できる。

また、スクリーンショット同士の位置合わせを容易にするために、[違いをハイライト]することができる。メインダイアログ上で、このチェックボックスをオンにしておくと(デフォルトオン)、スクリーンショット同士で重なり合う部分で、色が指定の閾値以上違う部分を赤くハイライトする。




[スクリーンショットについて]
ゲーム自体にスクリーンショット機能がある場合は、それを使った方がいい。とくにエミュレータベースのもの。

ゲームのスクリーンショットには、マップを表示している範囲と、ステータス表示の範囲がある。マップ作製には、ステータス表示の部分は不要なので、トリムする必要がある。トリム範囲は、スクリーンショットを読み込んで選んだ状態で、[編集]->[トリム]を選ぶことで指定可能。スクリーンショットの周囲に4本のハンドルを表示するので、それをマウスでつまんで、ドラッグして範囲を指定できる。

スクリーンショットの配置には、移動の最小単位(ピクセル数)を指定することができる。レトロゲームだと、マップは16ピクセルとか8ピクセル単位でスクロールするものが多い。8ピクセルでスクロールすればスムーズスクロールだったんだよ、当時は。ザナドゥなんかだと40ピクセル単位、だったかな？50だっけ？とにかく、そういう場合、1ピクセル単位でスクリーンショットを移動して張り合わせるのは効率が悪くて、移動の最小単位を指定しておくと楽に位置合わせができる。最小単位は、ワールドごとの設定で、[ワールド]->[単位の指定]で指定可能。





[3次元化]
なお、このユーザインターフェースは、3次元データを扱うツールを作るために作ったものなので、ビューコントロールダイアログの回転ロックを解除すると、Shift + 右ボタンドラッグで、マップを三次元的に回転することができる。

まったく意味ないけど。





