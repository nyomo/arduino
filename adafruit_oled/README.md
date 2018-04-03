# adafruit の OLED をattiny85で光らせる

## 準備

 1. arduino IDEを入れる
 1. avrisp mk2等AVR用のライターを使える様にする
 1. ツール→ボード→追加のボードマネージャに以下のURLを入れる
https://raw.githubusercontent.com/damellis/attiny/ide-1.6.x-boards-manager/package_damellis_attiny_index.json
 1. ボードマネージャでattinyを検索してinstall
 1. スケッチ→ライブラリをインクルード→ライブラリを管理で`SSD 1306` を検索して `Adafruit SSD1306 by Adafruit` をインストールする  
 1. 同じく `TinyWireM` を検索して `TinyWireM by Adafruit`をインストールする
