document.addEventListener('DOMContentLoaded', () => {
    const gameBoard = document.getElementById('game-board');
    const scoreDisplay = document.getElementById('score');
    const bestScoreDisplay = document.getElementById('best-score');
    const gameOverPopup = document.getElementById('game-over-popup');
    const size = 4;
    let board = [];
    let score = 0;
    let bestScore = 0;
    let autoPlay = false;
    let autoPlayEnabled = false;

    // Initialize the game board
    function initBoard() {
        board = Array(size).fill().map(() => Array(size).fill(0));
        addRandomTile();
        addRandomTile();
        renderBoard();
    }

    // Add a random tile to the board
    function addRandomTile() {
        const emptyTiles = [];
        for (let r = 0; r < size; r++) {
            for (let c = 0; c < size; c++) {
                if (board[r][c] === 0) {
                    emptyTiles.push({ r, c });
                }
            }
        }
        if (emptyTiles.length > 0) {
            const { r, c } = emptyTiles[Math.floor(Math.random() * emptyTiles.length)];
            board[r][c] = Math.random() < 0.9 ? 2 : 4;
        }
    }

    // Render the board
    function renderBoard() {
        gameBoard.innerHTML = '';
        for (let r = 0; r < size; r++) {
            for (let c = 0; c < size; c++) {
                const tile = document.createElement('div');
                tile.className = 'tile';
                if (board[r][c] !== 0) {
                    tile.textContent = board[r][c];
                    tile.dataset.value = board[r][c];
                }
                gameBoard.appendChild(tile);
            }
        }
        scoreDisplay.textContent = score;
        bestScoreDisplay.textContent = bestScore;
    }

    // Handle key press events
    function handleKeyPress(event) {
        if (!autoPlay) {
            switch (event.key) {
                case 'ArrowUp':
                    moveUp();
                    break;
                case 'ArrowDown':
                    moveDown();
                    break;
                case 'ArrowLeft':
                    moveLeft();
                    break;
                case 'ArrowRight':
                    moveRight();
                    break;
            }
            addRandomTile();
            renderBoard();
            if (isGameOver()) {
                gameOver();
            }
        }
    }

    // Move tiles up
    function moveUp() {
        for (let c = 0; c < size; c++) {
            let column = board.map(row => row[c]);
            column = mergeTiles(column);
            for (let r = 0; r < size; r++) {
                board[r][c] = column[r];
            }
        }
    }

    // Move tiles down
    function moveDown() {
        for (let c = 0; c < size; c++) {
            let column = board.map(row => row[c]);
            column = mergeTiles(column.reverse()).reverse();
            for (let r = 0; r < size; r++) {
                board[r][c] = column[r];
            }
        }
    }

    // Move tiles left
    function moveLeft() {
        for (let r = 0; r < size; r++) {
            board[r] = mergeTiles(board[r]);
        }
    }

    // Move tiles right
    function moveRight() {
        for (let r = 0; r < size; r++) {
            board[r] = mergeTiles(board[r].reverse()).reverse();
        }
    }

    // Merge tiles
    function mergeTiles(tiles) {
        tiles = tiles.filter(tile => tile !== 0);
        for (let i = 0; i < tiles.length - 1; i++) {
            if (tiles[i] === tiles[i + 1]) {
                tiles[i] *= 2;
                score += tiles[i];
                tiles[i + 1] = 0;
            }
        }
        return tiles.filter(tile => tile !== 0).concat(Array(size).fill(0)).slice(0, size);
    }

    // Check if the game is over
    function isGameOver() {
        for (let r = 0; r < size; r++) {
            for (let c = 0; c < size; c++) {
                if (board[r][c] === 0) return false;
                if (r > 0 && board[r][c] === board[r - 1][c]) return false;
                if (r < size - 1 && board[r][c] === board[r + 1][c]) return false;
                if (c > 0 && board[r][c] === board[r][c - 1]) return false;
                if (c < size - 1 && board[r][c] === board[r][c + 1]) return false;
            }
        }
        return true;
    }

    // Handle game over
    function gameOver() {
        gameOverPopup.classList.remove('hidden');
        if (score > bestScore) {
            bestScore = score;
            bestScoreDisplay.textContent = bestScore;
        }
        setTimeout(() => {
            gameOverPopup.classList.add('hidden');
            resetGame();
        }, 2000);
    }

    // Reset the game
    function resetGame() {
        score = 0;
        initBoard();
        if (autoPlayEnabled) {
            autoPlayGame(enable);
        }
    }

    // Auto play the game
    function autoPlayGame() {
        if (enable) {
            const moves = ['ArrowUp', 'ArrowDown', 'ArrowLeft', 'ArrowRight'];
            const interval = setInterval(() => {
                if (isGameOver()) {
                    clearInterval(interval);
                    gameOver();
                    autoPlay = false;
                } else {
                    handleKeyPress({ key: moves[Math.floor(Math.random() * moves.length)] });
                }
            }, 200);
        }
    }

    // Initialize the game
    initBoard();
    document.addEventListener('keydown', handleKeyPress);

    // Expose the autoPlayGame function to the global scope
    window.autoPlayGame = autoPlayGame;
});
