#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>  

#define MAX_STACK_SIZE 100
#define MAX_EXPR_SIZE 100 

typedef char element;

typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

// 스택 초기화 함수
void init_stack(StackType* s) {
    s->top = -1;
}

// 스택 공백 상태 검출 함수
int is_empty(StackType* s) {
    return (s->top == -1);
}

// 스택 포화 상태 검출 함수
int is_full(StackType* s) {
    return (s->top == (MAX_STACK_SIZE - 1));
}

// 스택 삽입 함수
void push(StackType* s, element item) {
    if (is_full(s)) {
        fprintf(stderr, "스택 포화 에러\n");
        exit(1); // 프로그램 종료
    }
    s->data[++(s->top)] = item;
}

// 스택 삭제 함수
element pop(StackType* s) {
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1); // 프로그램 종료
    }
    return s->data[(s->top)--];
}

// 스택 top 확인 함수
element peek(StackType* s) {
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러 (peek)\n");
        exit(1); // 프로그램 종료
    }
    return s->data[s->top];
}

// 연산자 우선순위 반환
int prec(char op) {
    switch (op) {
    case '(': case ')': return 0; 
    case '+': case '-': return 1;
    case '*': case '/': return 2;
    }
    return -1; // 잘못된 연산자
}

// 중위 표기 -> 후위 표기
void infix_to_postfix(char infix_expr[], char postfix_expr[]) {
    int i = 0, j = 0; 
    char ch, top_op;
    StackType s;
    init_stack(&s);

    for (i = 0; infix_expr[i] != '\0'; i++) {
        ch = infix_expr[i];
        switch (ch) {
        case '+':
        case '-':
        case '*':
        case '/': 
            while (!is_empty(&s) && (peek(&s) != '(') && (prec(peek(&s)) >= prec(ch))) {
                postfix_expr[j++] = pop(&s);
            }
            push(&s, ch);
            break;
        case '(': 
            push(&s, ch);
            break;
        case ')': 
            top_op = pop(&s);
            while (top_op != '(') {
                postfix_expr[j++] = top_op;
                if (is_empty(&s)) { 
                    fprintf(stderr, "괄호쌍\n");
                    postfix_expr[0] = '\0'; 
                    return;
                }
                top_op = pop(&s);
            }
            break;
        default: 
            if (isdigit(ch)) {
                postfix_expr[j++] = ch;
            }
            else if (ch == ' ' || ch == '\t') {
            }
            else {
                fprintf(stderr, "잘못된 문자: %c\n", ch);
                postfix_expr[0] = '\0'; 
                return;
            }
            break;
        }
    }
    while (!is_empty(&s)) {
        top_op = pop(&s);
        if (top_op == '(') { 
            fprintf(stderr, "괄호쌍 오류\n");
            postfix_expr[0] = '\0'; 
            return;
        }
        postfix_expr[j++] = top_op;
    }
    postfix_expr[j] = '\0'; 
}

// 후위 표기 수식 계산
int eval_postfix(char exp[]) {
    int op1, op2, value, i = 0;
    char ch;
    StackType s;
    init_stack(&s);

    if (exp[0] == '\0') return 0; 

    for (i = 0; exp[i] != '\0'; i++) {
        ch = exp[i];
        if (isdigit(ch)) { 
            value = ch - '0'; 
            push(&s, (element)value); 
        }
        else { 
            op2 = (int)pop(&s);
            op1 = (int)pop(&s);
            switch (ch) {
            case '+': push(&s, (element)(op1 + op2)); break;
            case '-': push(&s, (element)(op1 - op2)); break;
            case '*': push(&s, (element)(op1 * op2)); break;
            case '/':
                if (op2 == 0) {
                    fprintf(stderr, "0으로 나누기 x\n");
                    return 0; 
                }
                push(&s, (element)(op1 / op2)); break;
            }
        }
    }
    if (is_empty(&s)) return 0; // 계산할 것이 없었거나 오류
    return (int)pop(&s); // 최종 결과 반환 시 (int)로 형변환
}


int main(void) {
    char infix_expr[MAX_EXPR_SIZE];
    char postfix_expr[MAX_EXPR_SIZE];
    int result;

    while (1) {
        printf("infix 수식을 입력하세요. (종료: 0) : ");
        if (fgets(infix_expr, sizeof(infix_expr), stdin) == NULL) {
            printf("입력 오류.\n");
            break;
        }

        infix_expr[strcspn(infix_expr, "\n")] = 0;

        if (strcmp(infix_expr, "0") == 0) {
            printf("postfix 수식 변환 결과 : 0\n");
            printf("종료\n");
            break;
        }

        // 중위식을 후위식으로 변환
        infix_to_postfix(infix_expr, postfix_expr);

        if (postfix_expr[0] == '\0' && strlen(infix_expr) > 0 && strcmp(infix_expr, "0") != 0) {
            printf("수식 변환에 실패했습니다.\n");
            continue; 
        }

        printf("postfix 수식 변환 결과 : %s\n", postfix_expr);

        if (postfix_expr[0] != '\0') {
            result = eval_postfix(postfix_expr);
            printf("수식 계산 결과 : %d\n", result);
        }
        else if (strlen(infix_expr) > 0) { 
            printf("수식 계산을 스킵\n");
        }
    }

    return 0;
}