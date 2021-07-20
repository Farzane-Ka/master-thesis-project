load fisheriris;
[~,~,label]=unique(species);%unique function [,label] make labels from small to big order with numeric 1,2,3
data=zscore(meas);
numlabel=max(label);
numIns=size(data,1);%return number of rows if size(data,2)return number od columns
idx=randperm(numIns);%return random number from 1 to numIns
numtrain=100;
numtest=numIns-numtrain;
traindata=data(idx(1:numtrain),:);
testdata=data(idx(numtrain+1:end),:);
trainlabel=label(idx(1:numtrain));
testlabel=label(idx(numtrain+1:end));



[C,gamma]=meshgrid(-5:2:15,-15:2:3);
CV_acc=zeros(numel(C),1);
%maximum=0;
for i=1:numel(C)
    %CV_acc(i)= svmtrain(trainlabel,traindata,'-s 0 -g', num2str(2^gamma(i)),'-c', num2str(2^C(i)), '-v 10');
    CV_acc(i)= svmtrain(trainlabel,traindata,...
        sprintf('-c %f -g %f -v %d', 2^C(i), 2^gamma(i), 5));
end
    
[a,idx]=max(CV_acc);
bestgamma=2^gamma(idx);
bestc=2^C(idx);
maximumAcc=a;
%  bestgamma=9;
% bestc=9;


model=cell(numlabel,1);
for k=1:numlabel
    model{k}=svmtrain(double(trainlabel==k),traindata,sprintf('-c %d -g %d -b %d', bestc, bestgamma, 1));%'-c 1 -g 0.2 -b 1');%
end
%#swprobability
prob=zeros(numtest,numlabel);
for k=1:numlabel
    [a,b,p]=svmpredict(double(testlabel==k),testdata, model{k}, '-b 1');%3khorouji dar predict vojood darad bordary az label va deghat va sevomi matrix az ehtemal ast
    prob(:,k)=p(:,model{k}.Label==1);%khoroujie train yek sakhtar ast ke .label be manie label of each  class ast
end
%# predict the class with the highest probability
[~,pred]=max(prob,[],2);%maximum element in 2th dimention
%accuracy
acc=sum(pred==testlabel) ./numel(testlabel);
C=confusionmat(testlabel,pred);
            




