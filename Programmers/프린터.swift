import Foundation

func solution(_ priorities: [Int], _ location: Int) -> Int {
    var jobs = [(Int, Int)]() //(work#, priority)
    priorities.enumerated().forEach{ (index, prior) in
        jobs.append((index, prior))                               
    }

    var found: Bool = false
    var order = 1
    while !found {
        let maxPriority = jobs.max { (prev, next) -> Bool in
            return prev.1 < next.1                     
        }!.1
        let work = jobs.remove(at: 0)
        if work.0 == location {
            if work.1 == maxPriority { found = true }
            else {
                jobs.append(work) 
            }
        } else {
            if work.1 == maxPriority {
                order += 1
            } else {
                jobs.append(work) 
            }
        }   
    }
    
    return order
}
