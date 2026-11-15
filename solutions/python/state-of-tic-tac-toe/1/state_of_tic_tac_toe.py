def gamestate(board):
    x_count = 0
    o_count = 0
    space_count = 0
    for i in range(len(board)):
        for j in range(len(board[i])):
            if board[i][j] == 'X':
                x_count += 1
            elif board[i][j] == 'O':
                o_count += 1
            else:
                space_count += 1
    if (board[0][0] == board[1][1] == board [2][2] or board[0][2] == board[1][1] == board[2][0]) and board[1][1] !=  ' ':
        return "win"
    if o_count > x_count:
        raise ValueError("Wrong turn order: O started")
    if x_count > o_count + 1:
        raise ValueError("Wrong turn order: X went twice")
    for i in range(len(board)):
        if board[i][0] == board[i][1] == board[i][2] != ' ':
            if board[i][0] == 'X' and x_count <= o_count:
                raise ValueError("Impossible board: game should have ended after the game was won")
            elif board[i][0] == 'O' and o_count < x_count:
                raise ValueError("Impossible board: game should have ended after the game was won")
            elif i < 2 and board[i + 1][0] == board[i + 1][1] == board[i + 1][2] != ' ':
                raise ValueError("Impossible board: game should have ended after the game was won")
            return "win"
        if board[0][i] == board[1][i] == board[2][i] != ' ':
            if board[0][i] == 'X' and x_count <= o_count:
                raise ValueError("Impossible board: game should have ended after the game was won")
            elif board[0][i] == 'O' and o_count < x_count:
                raise ValueError("Impossible board: game should have ended after the game was won")
            elif i < 2 and board[0][i + 1] == board[1][i + 1] == board[2][i + 1] != ' ':
                raise ValueError("Impossible board: game should have ended after the game was won")
            return "win"
    if space_count == 0:
        return "draw"
    return "ongoing"
