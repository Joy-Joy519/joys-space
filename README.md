# Joy's Space

個人作品展示與四款小遊戲的多頁式網站。使用 HTML5、CSS3、原生 JavaScript，支援響應式畫面。

## 預覽方式

在 `joys-space` 資料夾執行：

```bash
python -m http.server 8000
```

在瀏覽器開啟 `http://localhost:8000/`。**請使用本機 HTTP 伺服器**，因為 OOXX 原始碼展示需以 `fetch` 讀取檔案；直接雙擊 HTML (`file://`) 可能因安全限制無法載入。

## 網站頁面
- Home、About、Projects、Games、Contact
- Games：OOXX、2048、Emoji 記憶翻牌、1A2B

## 版本分支
- `develop`：開發與測試
- `main`：正式 GitHub Pages 發布
- 推送、合併 `main` 必須分別事先取得使用者同意。
- 首次正式發布預定標籤 `v1.0.0`（目前僅本機試作，尚未發布）。

## 素材來源
- `images/joy.jpg`：使用者提供的個人照片。
- `images/ooxx-original.png`：使用者指定的第二張原始 C 語言終端機截圖。
- `games/ooxx/original.c`：使用者提供的 `game.c` 原始版本（保留原檔內容）。

## 注意
- Contact 真實帳號尚未提供，因此使用待補文字。
- OOXX 人機模式僅顯示「功能開發中」。
- 成績儲存在瀏覽器 localStorage，不跨裝置同步。
- 這是本機預覽版，未建立遠端 GitHub Repo、未推送也未部署 GitHub Pages。
