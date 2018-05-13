---

<h1 id="tekadventure---epitech-project">TEKADVENTURE - EPITECH PROJECT</h1>
<h4 id="tekadventure---epitech-project">Made with - Matthieu Brault & Antoine Casse</h4>

<p>This is the last project of my first year at my computer science school named Epitech, the goal of this project was to create a Points and Click game.</p>
<p>The project was in C langage using CSFML Graphic library</p>
<h1 id="dofas">DOFAS</h1>
<p>So we created DOFAS a remake of Dofus the game</p>
<h2 id="pictures">PICTURES</h2>
<p><strong>GUI MAIN MENU</strong><br>
<img src="https://lh3.googleusercontent.com/_dd4le1UskMjPCYTcRpEJDA8PGT3lRzfgp6wKAQzRGazmKdLwBJaX9NRObc-4GYnBugmoMNB2tOb" alt="enter image description here" title="Gui Main Menu"><br>
<strong>GUI CHOOSE PLAYER</strong><br>
<img src="https://lh3.googleusercontent.com/N_TNQOVqkv7fQjKuJx33s0n2vLNT96gf2TxgRl0E-lEcaZQ5g7xrU95HGJCKjMQIE4zgGWLLlOSZ" alt="" title="Option Playe"><br>
<strong>IN GAME - MAP</strong><br>
<img src="https://lh3.googleusercontent.com/NyCY-RRffXaCcu30SE6fHtNx0zDsc7W5laWC8npl8VaZC9xOavV3sdE2S1hTKkrFabvfAODxo8XU" alt="" title="Map in game"><br>
<strong>DIALOG  PNJ - INGAME</strong><br>
<img src="https://lh3.googleusercontent.com/ZL4bHgANFFZG-vtLi5E7uxoh2UDLhGnZo-LmVvx8M592sW4SF-qOzoix5VTs6iYJ6Q4XS09Dkorf" alt="enter image description here"><br>
<img src="https://lh3.googleusercontent.com/Km_QQgcUxkUxvj1MlSwxnDFdex29E1dY1Iw4OkDDUfZFEFuI6HUyy7dj3GCHSmM_hnQ8OX-np_0B" alt="enter image description here"><br>
<strong>LOADING GAME</strong><br>
<img src="https://lh3.googleusercontent.com/hwoxYunwoGX6BCAT9m3vcs2p8tX2fBQ0PNfl9L26q6OY6y9ALxtdDMBdG0uHFmM2_ivQ22zo3O_D" alt="enter image description here"><br>
<strong>MAP EDITOR</strong><br>
<img src="https://lh3.googleusercontent.com/gd3IZGRXBZOIvBJF1wbTDhcZBb5i1hMAc_ru6K33GTdmyCAUt_-wEdmxYBjvAYXX5AowHsW44ecL" alt="" title="MAP EDITOR"><br>
<strong>TELEPORTER - MAP</strong><br>
<img src="https://lh3.googleusercontent.com/8zM3wNvXnkr5M-D18QnL2w6O_C1Lk2B-Um5wzyEAwhXJDU3lWZ3zHlZioFtmqjG-gPJCxVg85auf" alt="enter image description here"></p>
<h2 id="config-the-game">CONFIG THE GAME</h2>
<p>All of the game is generate by a file configuration</p>
<p>EXAMPLE :</p>
<pre><code>#DAFOS - CONFIGFILE
#TO KNOW EVERYTHING ABOUT THE YAML CONFIG OF DAFOS
#GO TO THIS WEBSITE : 51.51.51.51/dafos-api/
CONF-LEVEL-1:
map-content:
00000011111111100
00000011111111100
00000001111111110
00000001111111100
map:
	map-name: "LEVEL-1"
	map-debug: 0
	map-bg: "ressources/backgrounds/mapstart2.png"
	map-music: "ressources/music/dofas_debut.ogg"
	map-player: 8,15
	map-decor: "ressources/decor/decor_map01.png"
	map-music: "ressources/music/dofas_debut.ogg"
	map-tile: "ressources/misc/tile_tp.png"
teleporter:
	teleporter-nb: 1
		tp-1:
			coords: 7,5
			tp-name: "tp1-LEVEL-2"
			tp-load: 0
event:
	event-nb: 3
		items-1:
			name: "Avalon"
			texture: "ressources/quest/character/avalon.png"
			coords: 4,9
			pnj: 1
			dialog: "ressources/dialog/avalon.txt"
			quest-pic: "ressources/quest/quest_pic/quest_debut.png"
		items-2:
			name: "Guard 1"
			texture: "ressources/quest/character/oto_mustam.png"
			coords: 4,10
			pnj: 0
			dialog: "ressources/dialog/oso_mustam.txt"
			quest-pic: "ressources/quest/quest_pic/oto_mustam.png"
		items-3:
			name: "Guard 2"
			texture: "ressources/quest/character/oto_mustam.png"
			coords: 4,8
			pnj: 0
			dialog: "ressources/dialog/oto_mustam.txt"
			quest-pic: "ressources/quest/quest_pic/oto_mustam.png"
</code></pre>

