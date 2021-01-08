import Foundation

func solution(_ bridge_length:Int, _ weight:Int, _ truck_weights:[Int]) -> Int {
    
    var trucks = [Int](truck_weights.reversed())
    var onBridge = [Int]()
    var weightSum = 0 // bridge weight
    var time = 0

    while !trucks.isEmpty {
        time += 1
        if onBridge.count == bridge_length {
            let truck = onBridge.removeFirst()
            weightSum -= truck
        }

        if weightSum + trucks.last! <= weight {
            let truck = trucks.popLast()!
            onBridge.append(truck)
            weightSum += truck
        } else {
            onBridge.append(0)
        }
    }
    
    return time + bridge_length
}
