import Foundation

func solution(_ progresses:[Int], _ speeds:[Int]) -> [Int] {
    var daysToFinish = [Double]()

    progresses.map { Double($0) * 1.0 }.enumerated().forEach { (idx, work) in
        let days = ceil((100.0 - work) / Double(speeds[idx]))
        daysToFinish.append(days)
    }

    var worksToRelease = [Int]()
    var asOf = daysToFinish[0]
    var addCnt = 1

    for i in 1..<daysToFinish.count {
        if daysToFinish[i] <= asOf {
            addCnt += 1
            continue
        } else {
            worksToRelease.append(addCnt)
            asOf = daysToFinish[i]
            addCnt = 1
        }
    }
    worksToRelease.append(addCnt)

    return worksToRelease
}
