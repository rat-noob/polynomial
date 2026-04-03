
// Generated from grammar/Polynomial.g4 by ANTLR 4.13.2


#include "PolynomialVisitor.h"

#include "PolynomialParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct PolynomialParserStaticData final {
  PolynomialParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  PolynomialParserStaticData(const PolynomialParserStaticData&) = delete;
  PolynomialParserStaticData(PolynomialParserStaticData&&) = delete;
  PolynomialParserStaticData& operator=(const PolynomialParserStaticData&) = delete;
  PolynomialParserStaticData& operator=(PolynomialParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag polynomialParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<PolynomialParserStaticData> polynomialParserStaticData = nullptr;

void polynomialParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (polynomialParserStaticData != nullptr) {
    return;
  }
#else
  assert(polynomialParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<PolynomialParserStaticData>(
    std::vector<std::string>{
      "prog", "stat", "poly", "term", "sign", "coefficient", "variables", 
      "var"
    },
    std::vector<std::string>{
      "", "'='", "'exit'", "'+'", "'-'", "'^'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "VAR", "NUM", "ID", "WS"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,9,61,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,7,
  	7,7,1,0,4,0,18,8,0,11,0,12,0,19,1,1,1,1,1,1,1,1,1,1,3,1,27,8,1,1,2,1,
  	2,1,2,5,2,32,8,2,10,2,12,2,35,9,2,1,3,3,3,38,8,3,1,3,1,3,3,3,42,8,3,1,
  	4,1,4,1,5,3,5,47,8,5,1,5,1,5,1,6,4,6,52,8,6,11,6,12,6,53,1,7,1,7,1,7,
  	3,7,59,8,7,1,7,0,0,8,0,2,4,6,8,10,12,14,0,1,1,0,3,4,61,0,17,1,0,0,0,2,
  	26,1,0,0,0,4,28,1,0,0,0,6,41,1,0,0,0,8,43,1,0,0,0,10,46,1,0,0,0,12,51,
  	1,0,0,0,14,55,1,0,0,0,16,18,3,2,1,0,17,16,1,0,0,0,18,19,1,0,0,0,19,17,
  	1,0,0,0,19,20,1,0,0,0,20,1,1,0,0,0,21,22,5,8,0,0,22,23,5,1,0,0,23,27,
  	3,4,2,0,24,27,3,4,2,0,25,27,5,2,0,0,26,21,1,0,0,0,26,24,1,0,0,0,26,25,
  	1,0,0,0,27,3,1,0,0,0,28,33,3,6,3,0,29,30,7,0,0,0,30,32,3,6,3,0,31,29,
  	1,0,0,0,32,35,1,0,0,0,33,31,1,0,0,0,33,34,1,0,0,0,34,5,1,0,0,0,35,33,
  	1,0,0,0,36,38,3,10,5,0,37,36,1,0,0,0,37,38,1,0,0,0,38,39,1,0,0,0,39,42,
  	3,12,6,0,40,42,3,10,5,0,41,37,1,0,0,0,41,40,1,0,0,0,42,7,1,0,0,0,43,44,
  	7,0,0,0,44,9,1,0,0,0,45,47,3,8,4,0,46,45,1,0,0,0,46,47,1,0,0,0,47,48,
  	1,0,0,0,48,49,5,7,0,0,49,11,1,0,0,0,50,52,3,14,7,0,51,50,1,0,0,0,52,53,
  	1,0,0,0,53,51,1,0,0,0,53,54,1,0,0,0,54,13,1,0,0,0,55,58,5,6,0,0,56,57,
  	5,5,0,0,57,59,5,7,0,0,58,56,1,0,0,0,58,59,1,0,0,0,59,15,1,0,0,0,8,19,
  	26,33,37,41,46,53,58
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  polynomialParserStaticData = std::move(staticData);
}

}

PolynomialParser::PolynomialParser(TokenStream *input) : PolynomialParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

PolynomialParser::PolynomialParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  PolynomialParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *polynomialParserStaticData->atn, polynomialParserStaticData->decisionToDFA, polynomialParserStaticData->sharedContextCache, options);
}

PolynomialParser::~PolynomialParser() {
  delete _interpreter;
}

const atn::ATN& PolynomialParser::getATN() const {
  return *polynomialParserStaticData->atn;
}

std::string PolynomialParser::getGrammarFileName() const {
  return "Polynomial.g4";
}

const std::vector<std::string>& PolynomialParser::getRuleNames() const {
  return polynomialParserStaticData->ruleNames;
}

const dfa::Vocabulary& PolynomialParser::getVocabulary() const {
  return polynomialParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView PolynomialParser::getSerializedATN() const {
  return polynomialParserStaticData->serializedATN;
}


//----------------- ProgContext ------------------------------------------------------------------

PolynomialParser::ProgContext::ProgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PolynomialParser::StatContext *> PolynomialParser::ProgContext::stat() {
  return getRuleContexts<PolynomialParser::StatContext>();
}

PolynomialParser::StatContext* PolynomialParser::ProgContext::stat(size_t i) {
  return getRuleContext<PolynomialParser::StatContext>(i);
}


size_t PolynomialParser::ProgContext::getRuleIndex() const {
  return PolynomialParser::RuleProg;
}


std::any PolynomialParser::ProgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PolynomialVisitor*>(visitor))
    return parserVisitor->visitProg(this);
  else
    return visitor->visitChildren(this);
}

PolynomialParser::ProgContext* PolynomialParser::prog() {
  ProgContext *_localctx = _tracker.createInstance<ProgContext>(_ctx, getState());
  enterRule(_localctx, 0, PolynomialParser::RuleProg);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(17); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(16);
      stat();
      setState(19); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 476) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatContext ------------------------------------------------------------------

PolynomialParser::StatContext::StatContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PolynomialParser::StatContext::getRuleIndex() const {
  return PolynomialParser::RuleStat;
}

void PolynomialParser::StatContext::copyFrom(StatContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ExitContext ------------------------------------------------------------------

PolynomialParser::ExitContext::ExitContext(StatContext *ctx) { copyFrom(ctx); }


std::any PolynomialParser::ExitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PolynomialVisitor*>(visitor))
    return parserVisitor->visitExit(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignContext ------------------------------------------------------------------

tree::TerminalNode* PolynomialParser::AssignContext::ID() {
  return getToken(PolynomialParser::ID, 0);
}

PolynomialParser::PolyContext* PolynomialParser::AssignContext::poly() {
  return getRuleContext<PolynomialParser::PolyContext>(0);
}

PolynomialParser::AssignContext::AssignContext(StatContext *ctx) { copyFrom(ctx); }


std::any PolynomialParser::AssignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PolynomialVisitor*>(visitor))
    return parserVisitor->visitAssign(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PrintExprContext ------------------------------------------------------------------

PolynomialParser::PolyContext* PolynomialParser::PrintExprContext::poly() {
  return getRuleContext<PolynomialParser::PolyContext>(0);
}

PolynomialParser::PrintExprContext::PrintExprContext(StatContext *ctx) { copyFrom(ctx); }


std::any PolynomialParser::PrintExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PolynomialVisitor*>(visitor))
    return parserVisitor->visitPrintExpr(this);
  else
    return visitor->visitChildren(this);
}
PolynomialParser::StatContext* PolynomialParser::stat() {
  StatContext *_localctx = _tracker.createInstance<StatContext>(_ctx, getState());
  enterRule(_localctx, 2, PolynomialParser::RuleStat);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(26);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case PolynomialParser::ID: {
        _localctx = _tracker.createInstance<PolynomialParser::AssignContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(21);
        match(PolynomialParser::ID);
        setState(22);
        match(PolynomialParser::T__0);
        setState(23);
        poly();
        break;
      }

      case PolynomialParser::T__2:
      case PolynomialParser::T__3:
      case PolynomialParser::VAR:
      case PolynomialParser::NUM: {
        _localctx = _tracker.createInstance<PolynomialParser::PrintExprContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(24);
        poly();
        break;
      }

      case PolynomialParser::T__1: {
        _localctx = _tracker.createInstance<PolynomialParser::ExitContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(25);
        match(PolynomialParser::T__1);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PolyContext ------------------------------------------------------------------

PolynomialParser::PolyContext::PolyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PolynomialParser::TermContext *> PolynomialParser::PolyContext::term() {
  return getRuleContexts<PolynomialParser::TermContext>();
}

PolynomialParser::TermContext* PolynomialParser::PolyContext::term(size_t i) {
  return getRuleContext<PolynomialParser::TermContext>(i);
}


size_t PolynomialParser::PolyContext::getRuleIndex() const {
  return PolynomialParser::RulePoly;
}


std::any PolynomialParser::PolyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PolynomialVisitor*>(visitor))
    return parserVisitor->visitPoly(this);
  else
    return visitor->visitChildren(this);
}

PolynomialParser::PolyContext* PolynomialParser::poly() {
  PolyContext *_localctx = _tracker.createInstance<PolyContext>(_ctx, getState());
  enterRule(_localctx, 4, PolynomialParser::RulePoly);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(28);
    term();
    setState(33);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(29);
        antlrcpp::downCast<PolyContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!(_la == PolynomialParser::T__2

        || _la == PolynomialParser::T__3)) {
          antlrcpp::downCast<PolyContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(30);
        term(); 
      }
      setState(35);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TermContext ------------------------------------------------------------------

PolynomialParser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

PolynomialParser::VariablesContext* PolynomialParser::TermContext::variables() {
  return getRuleContext<PolynomialParser::VariablesContext>(0);
}

PolynomialParser::CoefficientContext* PolynomialParser::TermContext::coefficient() {
  return getRuleContext<PolynomialParser::CoefficientContext>(0);
}


size_t PolynomialParser::TermContext::getRuleIndex() const {
  return PolynomialParser::RuleTerm;
}


std::any PolynomialParser::TermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PolynomialVisitor*>(visitor))
    return parserVisitor->visitTerm(this);
  else
    return visitor->visitChildren(this);
}

PolynomialParser::TermContext* PolynomialParser::term() {
  TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, getState());
  enterRule(_localctx, 6, PolynomialParser::RuleTerm);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(41);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(37);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 152) != 0)) {
        setState(36);
        coefficient();
      }
      setState(39);
      variables();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(40);
      coefficient();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SignContext ------------------------------------------------------------------

PolynomialParser::SignContext::SignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t PolynomialParser::SignContext::getRuleIndex() const {
  return PolynomialParser::RuleSign;
}


std::any PolynomialParser::SignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PolynomialVisitor*>(visitor))
    return parserVisitor->visitSign(this);
  else
    return visitor->visitChildren(this);
}

PolynomialParser::SignContext* PolynomialParser::sign() {
  SignContext *_localctx = _tracker.createInstance<SignContext>(_ctx, getState());
  enterRule(_localctx, 8, PolynomialParser::RuleSign);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(43);
    _la = _input->LA(1);
    if (!(_la == PolynomialParser::T__2

    || _la == PolynomialParser::T__3)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CoefficientContext ------------------------------------------------------------------

PolynomialParser::CoefficientContext::CoefficientContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PolynomialParser::CoefficientContext::NUM() {
  return getToken(PolynomialParser::NUM, 0);
}

PolynomialParser::SignContext* PolynomialParser::CoefficientContext::sign() {
  return getRuleContext<PolynomialParser::SignContext>(0);
}


size_t PolynomialParser::CoefficientContext::getRuleIndex() const {
  return PolynomialParser::RuleCoefficient;
}


std::any PolynomialParser::CoefficientContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PolynomialVisitor*>(visitor))
    return parserVisitor->visitCoefficient(this);
  else
    return visitor->visitChildren(this);
}

PolynomialParser::CoefficientContext* PolynomialParser::coefficient() {
  CoefficientContext *_localctx = _tracker.createInstance<CoefficientContext>(_ctx, getState());
  enterRule(_localctx, 10, PolynomialParser::RuleCoefficient);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(46);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PolynomialParser::T__2

    || _la == PolynomialParser::T__3) {
      setState(45);
      sign();
    }
    setState(48);
    match(PolynomialParser::NUM);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariablesContext ------------------------------------------------------------------

PolynomialParser::VariablesContext::VariablesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<PolynomialParser::VarContext *> PolynomialParser::VariablesContext::var() {
  return getRuleContexts<PolynomialParser::VarContext>();
}

PolynomialParser::VarContext* PolynomialParser::VariablesContext::var(size_t i) {
  return getRuleContext<PolynomialParser::VarContext>(i);
}


size_t PolynomialParser::VariablesContext::getRuleIndex() const {
  return PolynomialParser::RuleVariables;
}


std::any PolynomialParser::VariablesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PolynomialVisitor*>(visitor))
    return parserVisitor->visitVariables(this);
  else
    return visitor->visitChildren(this);
}

PolynomialParser::VariablesContext* PolynomialParser::variables() {
  VariablesContext *_localctx = _tracker.createInstance<VariablesContext>(_ctx, getState());
  enterRule(_localctx, 12, PolynomialParser::RuleVariables);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(51); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(50);
              var();
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(53); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarContext ------------------------------------------------------------------

PolynomialParser::VarContext::VarContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* PolynomialParser::VarContext::VAR() {
  return getToken(PolynomialParser::VAR, 0);
}

tree::TerminalNode* PolynomialParser::VarContext::NUM() {
  return getToken(PolynomialParser::NUM, 0);
}


size_t PolynomialParser::VarContext::getRuleIndex() const {
  return PolynomialParser::RuleVar;
}


std::any PolynomialParser::VarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<PolynomialVisitor*>(visitor))
    return parserVisitor->visitVar(this);
  else
    return visitor->visitChildren(this);
}

PolynomialParser::VarContext* PolynomialParser::var() {
  VarContext *_localctx = _tracker.createInstance<VarContext>(_ctx, getState());
  enterRule(_localctx, 14, PolynomialParser::RuleVar);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(55);
    match(PolynomialParser::VAR);
    setState(58);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == PolynomialParser::T__4) {
      setState(56);
      match(PolynomialParser::T__4);
      setState(57);
      match(PolynomialParser::NUM);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void PolynomialParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  polynomialParserInitialize();
#else
  ::antlr4::internal::call_once(polynomialParserOnceFlag, polynomialParserInitialize);
#endif
}
