# pragma once
# include <Siv3D.hpp>

struct Game {

	// ゲームタイトル(フル)
	String title;

	// 実行ファイルのパス
	FilePath path;

	// ゲームの画像
	Texture screenshot;

	// readmeファイルのパス
	FilePath rdmPath;

	// readmeの内容
	Texture readme;

	// ゲーム開発ツール
	String tools;

	// ゲームジャンル
	String kind;

	// 開発者
	String staff;

	// マウスを使用するか
	bool useMouse = false;

	// キーボードを使用するか
	bool useKeyboard = false;

	// ゲームパッドを使用するか
	bool useGamepad = false;

	// ブラウザで起動する必要があるかどうか
	bool isWebApp = false;

	// 動画があるかどうか
	// bool hasMovie = false;

	// 紹介動画

};