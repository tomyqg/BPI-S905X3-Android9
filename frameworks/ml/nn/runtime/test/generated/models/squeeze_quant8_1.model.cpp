// Generated file (from: squeeze_quant8_1.mod.py). Do not edit
void CreateModel(Model *model) {
  OperandType type1(Type::TENSOR_INT32, {1});
  OperandType type0(Type::TENSOR_QUANT8_ASYMM, {1, 24, 1}, 1.0, 0);
  OperandType type2(Type::TENSOR_QUANT8_ASYMM, {1, 24}, 1.0, 0);
  // Phase 1, operands
  auto input = model->addOperand(&type0);
  auto squeezeDims = model->addOperand(&type1);
  auto output = model->addOperand(&type2);
  // Phase 2, operations
  static int32_t squeezeDims_init[] = {2};
  model->setOperandValue(squeezeDims, squeezeDims_init, sizeof(int32_t) * 1);
  model->addOperation(ANEURALNETWORKS_SQUEEZE, {input, squeezeDims}, {output});
  // Phase 3, inputs and outputs
  model->identifyInputsAndOutputs(
    {input},
    {output});
  assert(model->isValid());
}

bool is_ignored(int i) {
  static std::set<int> ignore = {};
  return ignore.find(i) != ignore.end();
}
