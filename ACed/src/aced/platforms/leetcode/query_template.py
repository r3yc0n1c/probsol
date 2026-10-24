"""
query_template.py
Stores clean, isolated GraphQL queries and mutations for LeetCode, CF, CC
"""

"""
====================
Problemset page queries
====================
"""

QUESTION_OF_THE_DAY = """
query questionOfToday {
  activeDailyCodingChallengeQuestion {
    date
    userStatus
    link
    question {
      acRate
      difficulty
      freqBar
      frontendQuestionId: questionFrontendId
      isFavor
      paidOnly: isPaidOnly
      status
      title
      titleSlug
      hasVideoSolution
      hasSolution
      topicTags {
        name
        id
        slug
      }
    }
  }
}
"""

PROBLEMSET_QUESTION_LIST = """
query problemsetQuestionList(
  $categorySlug: String
  $limit: Int
  $skip: Int
  $filters: QuestionListFilterInput
) {
  problemsetQuestionList: questionList(
    categorySlug: $categorySlug
    limit: $limit
    skip: $skip
    filters: $filters
  ) {
    total: totalNum
    questions: data {
      acRate
      difficulty
      freqBar
      frontendQuestionId: questionFrontendId
      isFavor
      paidOnly: isPaidOnly
      status
      title
      titleSlug
      topicTags {
        name
        id
        slug
      }
      hasSolution
      hasVideoSolution
    }
  }
}
"""
# {"categorySlug": "", "skip": 0, "limit": 50, "filters": {}}
# Get question by question ID
# { "categorySlug": "", "skip": 0, "limit": 50, "filters": { "searchKeywords": "3644" }}

"""
========================================
Problem Solve page queries
========================================
"""

QUESTION_CONTENT = """
query questionContent($titleSlug: String!) {
  question(titleSlug: $titleSlug) {
    content
    mysqlSchemas
  }
}
"""
# {"titleSlug": "two-sum"}


QUESTION_EDITOR_DATA = """
query questionEditorData($titleSlug: String!) {
  question(titleSlug: $titleSlug) {
    questionId
    questionFrontendId
    codeSnippets {
      lang
      langSlug
      code
    }
    envInfo
    enableRunCode
  }
}
"""
# {"titleSlug": "two-sum"}

QUESTION_CONTENT_WITH_EDITOR_DATA = """
query questionContentWithEditorData($titleSlug: String!) {
  question(titleSlug: $titleSlug) {
    questionId
    questionFrontendId
    content
    mysqlSchemas
    codeSnippets {
      lang
      langSlug
      code
    }
  }
}
"""
# {"titleSlug": "two-sum"}

PANEL_QUESTION_LIST = """
query panelQuestionList(
  $currentQuestionSlug: String!
  $categorySlug: String
  $envId: String
  $envType: String
  $filters: QuestionListFilterInput
) {
  panelQuestionList(
    currentQuestionSlug: $currentQuestionSlug
    categorySlug: $categorySlug
    envId: $envId
    envType: $envType
    filters: $filters
  ) {
    hasViewPermission
    panelName
    finishedLength
    totalLength
    questions {
      difficulty
      id
      paidOnly
      questionFrontendId
      status
      title
      titleSlug
      topicTags {
        name
        slug
      }
    }
  }
}
"""
# {"currentQuestionSlug": "two-sum", "filters": {}, "envId": "", "envType": "problem-list"}
# {"envType": "", "envId": "", "currentQuestionSlug": "two-sum"}
# {"envType": "contest", "envId": "weekly-contest-521", "currentQuestionSlug": "rearrange-array-by-removing-distinct-values"}