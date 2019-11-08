# Programming contest solutions by pione

プログラミングコンテストの **C++** による解答のリポジトリ

## おまけ C++競プロ環境

### これは何？

外出先でPC忘れてもすぐ競プロできるようにするため自分用に作った

自分用なので動作は保証しない

### 環境構築

#### WSL導入

[参考] https://qiita.com/AokabiC/items/e9312856f588dd9303ed

PowerShell 上で以下を実行

```PowerShell
Enable-WindowsOptionalFeature -Online -FeatureName Microsoft-Windows-Subsystem-Linux
```

Microsoft Store から **Ubuntu LTS** をインストール

Ubuntuを起動し、WSL上で以下を実行

```bash
sudo apt install build-essential
sudo apt install gdb
```

あとはこのリポジトリを clone し、VSCode で開けば `.vscode` 配下の設定ファイルを読み込んで WSL がターミナルとして使われるようになる

##### 最低限入れておくべき拡張機能

- C/C++
- Better C++ Syntax
- WSL workspaceFolder
- Remote - WSL

### 実行手順

プロジェクト配下に適当に `cpp` ファイルを作ればよい

- ビルド: `ctrl` + `shift` + `B`
- デバッグ: `problem.in` に入力値を設定して `F5`