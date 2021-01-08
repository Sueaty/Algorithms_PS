import Foundation

func solution(_ n: Int, _ a: Int, _ b: Int) -> Int {
    //total rounds
    let rounds = numberOfRounds(players: n)
    var matchRound = rounds
    var start = 1
    var end = n
    
    while matchRound > 1 {
        let inDiffGroup = playersInDiffGroup(start: start, end: end, a: a, b: b)
        if inDiffGroup { break }
        else {
            matchRound -= 1
            if a <= ((start + end - 1) / 2) {
                end = (start + end - 1) / 2
            } else {
                start = (start + end - 1) / 2 + 1
            }
        }
    }
    
    return matchRound
}

func numberOfRounds(players: Int) -> Int {
    var num = players
    var rounds = 0
    
    while num > 1 {
        num /= 2
        rounds += 1
    }
    
    return rounds
}

func playersInDiffGroup(start: Int, end: Int, a: Int, b: Int) -> Bool {
    let bound = (start + end - 1) / 2
    if a <= bound && b <= bound { return false }
    else if a > bound && b > bound { return false }
    return true
}
