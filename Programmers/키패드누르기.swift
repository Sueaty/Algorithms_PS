import Foundation

let keypad = [[0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1], // 0
              [0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0], // 1
              [0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0], // 2
              [0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0], // 3
              [0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0], // 4
              [0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0], // 5
              [0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0], // 6
              [0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0], // 7
              [1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0], // 8
              [0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1], // 9
              [1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0], // 10 (#)
              [1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0]] // 11 (*)

func solution(_ numbers: [Int], _ hand: String) -> String {
    var lpos = 10
    var rpos = 11
    var answer = ""

    numbers.forEach { num in
        if num == 1 || num == 4 || num == 7 || num == 10 {
            lpos = num
            answer += "L"
        } else if num == 3 || num == 6 || num == 9 || num == 11 {
            rpos = num
            answer += "R"
        } else {
            // use bfs to get the shortest path
            let fromL = shortestPath(from: lpos, to: num)
            let fromR = shortestPath(from: rpos, to: num)
            if fromL < fromR {
                lpos = num
                answer += "L"
            } else if fromL > fromR {
                rpos = num
                answer += "R"
            } else {
                if hand == "left" {
                    lpos = num
                    answer += "L"
                } else {
                    rpos = num
                    answer += "R"
                }
            }
        }
    }
    
    return answer
}

func shortestPath(from: Int, to: Int) -> Int {
    var visited = Array(repeating: false, count: 12)
    var stack = [(from, 0)] // num, distance
    var answer = 0
    
    while !visited[to] {
        let popped = stack.removeFirst()
        visited[popped.0] = true
        answer = popped.1
        
        keypad[popped.0].enumerated().forEach { (idx, indicator) in
            if !visited[idx] && indicator == 1 {
                stack.append((idx, popped.1 + 1))
            }
        }
    }
    return answer
}
