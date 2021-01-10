import Foundation

func solution(_ n: Int, _ costs: [[Int]]) -> Int {
    func union(nodeA: Int, nodeB: Int, parentA: Int, parentB: Int) {
        if nodeA < nodeB { pTable[parentB] = parentA } 
        else { pTable[parentA] = parentB }
    }
    
    func find(node: Int) -> Int {
        if pTable[node] == node { return node }
        pTable[node] = find(node: pTable[node])
        return pTable[node]
    }
    
    var pTable = Array<Int>(0..<n)
    let graph = costs.sorted { $0[2] < $1[2] }
    
    var lines = 0
    var cost = 0
    for i in 0..<graph.count {
        if lines == n - 1 { break }
        let pA = find(node: graph[i][0])
        let pB = find(node: graph[i][1])
        if pA != pB {
            union(nodeA: graph[i][0], nodeB: graph[i][1], parentA: pA, parentB: pB)
            cost += graph[i][2]
            lines += 1
        }
    }
    
    return cost
}
